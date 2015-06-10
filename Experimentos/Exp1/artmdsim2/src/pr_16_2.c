
/* [[pr_16_2 - three-dimensional vibrating layer]] */


/*********************************************************************

  (C) 2004  D. C. Rapaport

  This software is copyright material accompanying the book
  "The Art of Molecular Dynamics Simulation", 2nd edition,
  by D. C. Rapaport, published by Cambridge University Press (2004).

**********************************************************************/


#include "in_mddefs.h"

typedef struct {
  VecR r, rv, ra, wv, wa;
  real diam;
} Mol;

Mol *mol;
VecR region;
VecI initUcell;
real deltaT, rCut, kinEnergy, timeNow, velMag;
int moreCycles, nMol, stepAvg, stepCount, stepLimit;
VecI cells;
int *cellList;
real dispHi, rNebrShell;
int *nebrTab, nebrNow, nebrTabFac, nebrTabLen, nebrTabMax;
real basePos, baseVel, curPhase, fricDyn, fricStat, gravField,
   inertiaK, vibAmp, vibFreq;
int nBaseCycle;
int runId, stepSnap;

NameList nameList[] = {
  NameR (deltaT),
  NameR (fricDyn),
  NameR (gravField),
  NameI (initUcell),
  NameI (nebrTabFac),
  NameR (rNebrShell),
  NameI (runId),
  NameI (stepAvg),
  NameI (stepLimit),
  NameI (stepSnap),
  NameR (vibAmp),
  NameR (vibFreq),
};


int main (int argc, char **argv)
{
  GetNameList (argc, argv);
  PrintNameList (stdout);
  SetParams ();
  SetupJob ();
  moreCycles = 1;
  PutConfig ();
  while (moreCycles) {
    SingleStep ();
    if (stepCount % stepSnap == 0) PutConfig ();
    if (stepCount >= stepLimit) moreCycles = 0;
  }
}

void SetupFiles ()
{
  FILE *fp;

  strcpy (fileName[FL_SNAP], fileNameR[FL_SNAP]);
  fileName[FL_SNAP][0] = progId[0];
  fileName[FL_SNAP][1] = progId[1];
  fileName[FL_SNAP][2] = runId / 10 + CHAR_ZERO;
  fileName[FL_SNAP][3] = runId % 10 + CHAR_ZERO;
  fp = fopen (fileName[FL_SNAP], "w");
  fclose (fp);
}


void SingleStep ()
{
  ++ stepCount;
  timeNow = stepCount * deltaT;
  SetBase ();
  LeapfrogStep (1);
  ApplyBoundaryCond ();
  if (nebrNow) {
    nebrNow = 0;
    dispHi = 0.;
    BuildNebrList ();
  }
  ComputeForces ();
  LeapfrogStep (2);
  EvalProps ();
  if (stepCount % stepAvg == 0) PrintSummary (stdout);
}

void SetupJob ()
{
  SetupFiles ();
  AllocArrays ();
  stepCount = 0;
  SetBase ();
  InitCoords ();
  InitVels ();
  InitAccels ();
  SetMolSizes ();
  nebrNow = 1;
}

void SetParams ()
{
  rCut = pow (2., 1./6.);
  region.x = initUcell.x / 0.95;
  region.y = region.x;
  region.z = region.x;
  nMol = VProd (initUcell);
  VSCopy (cells, 1. / (rCut + rNebrShell), region);
  nebrTabMax = nebrTabFac * nMol;
  fricStat = 0.5;
  inertiaK = 0.1;
  velMag = 1.;
}

void AllocArrays ()
{
  AllocMem (mol, nMol, Mol);
  AllocMem (cellList, VProd (cells) + nMol, int);
  AllocMem (nebrTab, 2 * nebrTabMax, int);
}

void BuildNebrList ()
{
  VecR dr, invWid, rs, shift;
  VecI cc, m1v, m2v, vOff[] = OFFSET_VALS, zz;
  real dFac;
  int c, j1, j2, m1, m1x, m1y, m1z, m2, n, offset;

  VDiv (invWid, cells, region);
  for (n = nMol; n < nMol + VProd (cells); n ++) cellList[n] = -1;
  VZero (zz);
  DO_MOL {
    VSAdd (rs, mol[n].r, 0.5, region);
    VMul (cc, rs, invWid);
    if (! (VGe (cc, zz) && VLt (cc, cells)))
       ErrExit (ERR_OUTSIDE_REGION);
    c = VLinear (cc, cells) + nMol;
    cellList[n] = cellList[c];
    cellList[c] = n;
  }
  nebrTabLen = 0;
  for (m1z = 0; m1z < cells.z; m1z ++) {
    for (m1y = 0; m1y < cells.y; m1y ++) {
      for (m1x = 0; m1x < cells.x; m1x ++) {
        VSet (m1v, m1x, m1y, m1z);
        m1 = VLinear (m1v, cells) + nMol;
        for (offset = 0; offset < N_OFFSET; offset ++) {
          VAdd (m2v, m1v, vOff[offset]);
          VZero (shift);
          VCellWrap (x);
          VCellWrap (y);
          if (m2v.z >= cells.z) continue;
          m2 = VLinear (m2v, cells) + nMol;
          DO_CELL (j1, m1) {
            DO_CELL (j2, m2) {
              if (m1 != m2 || j2 < j1) {
                VSub (dr, mol[j1].r, mol[j2].r);
                VVSub (dr, shift);
                dFac = 0.5 * (mol[j1].diam + mol[j2].diam);
                if (VLenSq (dr) < Sqr (rCut * dFac + rNebrShell)) {
                  if (nebrTabLen >= nebrTabMax)
                     ErrExit (ERR_TOO_MANY_NEBRS);
                  nebrTab[2 * nebrTabLen] = j1;
                  nebrTab[2 * nebrTabLen + 1] = j2;
                  ++ nebrTabLen;
                }
              }
            }
          }
        }
      }
    }
  }
}

void ComputeForces ()
{
  VecR dr, dv, ws, wt;
  real aMass, dFac, drv, fcVal, ft, ftLim, rr, rri, rri3, rSep, vRel;
  int j1, j2, n;

  DO_MOL {
    VZero (mol[n].ra);
    VZero (mol[n].wa);
  }
  for (n = 0; n < nebrTabLen; n ++) {
    j1 = nebrTab[2 * n];
    j2 = nebrTab[2 * n + 1];
    dFac = 0.5 * (mol[j1].diam + mol[j2].diam);
    VSub (dr, mol[j1].r, mol[j2].r);
    VWrap (dr, x);
    VWrap (dr, y);
    rr = VLenSq (dr);
    if (rr < Sqr (rCut * dFac)) {
      rSep = sqrt (rr);
      rri = Sqr (dFac) / rr;
      rri3 = Cube (rri);
      fcVal = 48. * rri3 * (rri3 - 0.5) / rr;
      VSub (dv, mol[j1].rv, mol[j2].rv);
      drv = VDot (dr, dv);
      fcVal -= fricDyn * drv / rr;
      VVSAdd (mol[j1].ra, fcVal, dr);
      VVSAdd (mol[j2].ra, - fcVal, dr);
      VVSAdd (dv, - drv / rr, dr);
      VSSAdd (ws, mol[j1].diam, mol[j1].wv, mol[j2].diam, mol[j2].wv);
      VScale (ws, 1. / (mol[j1].diam + mol[j2].diam));
      VCross (wt, ws, dr);
      VVSub (dv, wt);
      vRel = VLen (dv);
      ftLim = fricStat * fabs (fcVal) * rSep / vRel;
      ft = - Min (ftLim, fricDyn);
      VVSAdd (mol[j1].ra, ft, dv);
      VVSAdd (mol[j2].ra, - ft, dv);
      VCross (wt, dr, dv);
      VScale (wt, - ft / rSep);
      VVAdd (mol[j1].wa, wt);
      VVAdd (mol[j2].wa, wt);
    }
  }
  ComputeBdyForces ();
  DO_MOL {
    aMass = Cube (mol[n].diam);
    VScale (mol[n].ra, 1. / aMass);
    VScale (mol[n].wa, 1. / (2. * inertiaK * aMass * mol[n].diam));
    mol[n].ra.z -= gravField;
  }
}

void ComputeBdyForces ()
{
  VecR dr;
  real dFac, drv, fcVal, rr, rri, rri3;
  int n;

  DO_MOL {
    dFac = 0.5 * (mol[n].diam + 1.);
    dr.z = mol[n].r.z - 0.5 * region.z;
    if (fabs (dr.z) < rCut * dFac) {
      rr = Sqr (dr.z);
      rri = Sqr (dFac) / rr;
      rri3 = Cube (rri);
      fcVal = 48. * rri3 * (rri3 - 0.5) / rr;
      mol[n].ra.z += fcVal * dr.z;
    }
    dr.z = mol[n].r.z - basePos;
    if (fabs (dr.z) < rCut * dFac) {
      rr = Sqr (dr.z);
      rri = Sqr (dFac) / rr;
      rri3 = Cube (rri);
      fcVal = 48. * rri3 * (rri3 - 0.5) / rr;
      drv = dr.z * (mol[n].rv.z - baseVel);
      fcVal -= fricDyn * drv / rr;
      mol[n].ra.z += fcVal * dr.z;
    }
  }
}

void LeapfrogStep (int part)
{
  int n;

  if (part == 1) {
    DO_MOL {
      VVSAdd (mol[n].rv, 0.5 * deltaT, mol[n].ra);
      VVSAdd (mol[n].r, deltaT, mol[n].rv);
      VVSAdd (mol[n].wv, 0.5 * deltaT, mol[n].wa);
    }
  } else {
    DO_MOL {
      VVSAdd (mol[n].rv, 0.5 * deltaT, mol[n].ra);
      VVSAdd (mol[n].wv, 0.5 * deltaT, mol[n].wa);
    }
  }
}

void ApplyBoundaryCond ()
{
  int n;

  DO_MOL {
    VWrap (mol[n].r, x);
    VWrap (mol[n].r, y);
  }
}

void EvalProps ()
{
  real vv, vvMax, vvSum;
  int n;

  vvSum = 0.;
  vvMax = 0.;
  DO_MOL {
    vv = VLenSq (mol[n].rv);
    if (vv > vvMax) vvMax = vv;
    vvSum += Cube (mol[n].diam) * (vv + inertiaK *
       Sqr (mol[n].diam) * VLenSq (mol[n].wv));
  }
  dispHi += sqrt (vvMax) * deltaT;
  if (dispHi > rNebrShell * 0.5) nebrNow = 1;
  kinEnergy = 0.5 * vvSum / nMol;
}

void SetBase ()
{
  nBaseCycle = vibFreq * stepCount * deltaT;
  curPhase = vibFreq * stepCount * deltaT - nBaseCycle;
  basePos = - 0.5 * region.z + vibAmp * (1. - cos (2. * M_PI * curPhase));
  baseVel = 2. * M_PI * vibFreq * vibAmp * sin (2. * M_PI * curPhase);
}

void InitCoords ()
{
  VecR c, gap;
  int n, nx, ny, nz;

  VDiv (gap, region, initUcell);
  gap.z = rCut;
  n = 0;
  for (nz = 0; nz < initUcell.z; nz ++) {
    c.z = nz * gap.z + basePos + rCut;
    for (ny = 0; ny < initUcell.y; ny ++) {
      c.y = (ny + 0.5) * gap.y - 0.5 * region.y;
      for (nx = 0; nx < initUcell.x; nx ++) {
        c.x = (nx + 0.5) * gap.x - 0.5 * region.x;
        mol[n].r = c;
        ++ n;
      }
    }
  }
}

void InitVels ()
{
  int n;

  DO_MOL {
    VRand (&mol[n].rv);
    VScale (mol[n].rv, velMag);
    VZero (mol[n].wv);
  }
}

void InitAccels ()
{
  int n;

  DO_MOL {
    VZero (mol[n].ra);
    VZero (mol[n].wa);
  }
}

void SetMolSizes ()
{
  int n;

  DO_MOL mol[n].diam = 1. - 0.15 * RandR ();
}

void PrintSummary (FILE *fp)
{
  fprintf (fp, "%5d %8.4f %7.4f",
     stepCount, timeNow, kinEnergy);
  fprintf (fp, "\n");
  fflush (fp);
}

#define SCALE_FAC  32767.

void PutConfig ()
{
  VecR w;
  int blockSize, fOk, n;
  short *rI;
  FILE *fp;

  fOk = 1;
  blockSize = (NDIM + 3) * sizeof (real) + 4 * sizeof (int) +
     nMol * NDIM * sizeof (short);
  if ((fp = fopen (fileName[FL_SNAP], "a")) != 0) {
    WriteF (blockSize);
    WriteF (basePos);
    WriteF (curPhase);
    WriteF (nBaseCycle);
    WriteF (nMol);
    WriteF (region);
    WriteF (stepCount);
    WriteF (timeNow);
    AllocMem (rI, NDIM * nMol, short);
    DO_MOL {
      VDiv (w, mol[n].r, region);
      VAddCon (w, w, 0.5);
      VScale (w, SCALE_FAC);
      VToLin (rI, NDIM * n, w);
    }
    WriteFN (rI, NDIM * nMol);
    free (rI);
    if (ferror (fp)) fOk = 0;
    fclose (fp);
  } else fOk = 0;
  if (! fOk) ErrExit (ERR_SNAP_WRITE);
}

#include "in_rand.c"
#include "in_errexit.c"
#include "in_namelist.c"

