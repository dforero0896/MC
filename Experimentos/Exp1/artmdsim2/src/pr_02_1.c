
/* [[pr_02_1 - all pairs, two dimensions]] */


/*********************************************************************

  (C) 2004  D. C. Rapaport

  This software is copyright material accompanying the book
  "The Art of Molecular Dynamics Simulation", 2nd edition,
  by D. C. Rapaport, published by Cambridge University Press (2004).

**********************************************************************/

#include <stdio.h>

#define NDIM  2

#include "in_mddefs.h"

typedef struct {
  VecR r, rv, ra;
} Mol;

Mol *mol;
VecR region, vSum;
VecI initUcell;
real deltaT, density, rCut, temperature, timeNow, uSum, velMag, vvSum;
Prop kinEnergy, totEnergy;
int moreCycles, nMol, stepAvg, stepCount, stepEquil, stepLimit;
real virSum;
Prop pressure;

NameList nameList[] = {
  NameR (deltaT),
  NameR (density),
  NameI (initUcell),
  NameI (stepAvg),
  NameI (stepEquil),
  NameI (stepLimit),
  NameR (temperature),
};


int main (int argc, char **argv)
{
  GetNameList (argc, argv);
  //PrintNameList (stdout);
  SetParams ();
  SetupJob ();
  moreCycles = 1;
  PrintSummary (stdout);
  while (moreCycles) {
    SingleStep ();
    if (stepCount >= stepLimit) moreCycles = 0;
  }
}


void SingleStep ()
{
  ++ stepCount;
  timeNow = stepCount * deltaT;
  LeapfrogStep (1);
  ApplyBoundaryCond ();
  ComputeForces ();
  LeapfrogStep (2);
  //EvalProps ();
  //AccumProps (1);
  if (stepCount % stepAvg == 0) {
    //AccumProps (2);
    PrintSummary (stdout);
    //PrintVels (stdout);
    //AccumProps (0);
  }
}

void SetupJob ()
{
  AllocArrays ();
  stepCount = 0;
  InitCoords ();
  InitVels ();
  InitAccels ();
  AccumProps (0);
}

void SetParams ()
{
  rCut = pow (2., 1./6.);
  VSCopy (region, 1. / sqrt (density), initUcell);
  nMol = VProd (initUcell);
  velMag = sqrt (NDIM * (1. - 1. / nMol) * temperature);
}

void AllocArrays ()
{
  AllocMem (mol, nMol, Mol);
}


void ComputeForces ()
{
  VecR dr;
  real fcVal, rr, rrCut, rri, rri3;
  int j1, j2, n;

  rrCut = Sqr (rCut);
  DO_MOL VZero (mol[n].ra);
  uSum = 0.;
  virSum = 0.;
  for (j1 = 0; j1 < nMol - 1; j1 ++) {
    for (j2 = j1 + 1; j2 < nMol; j2 ++) {
      VSub (dr, mol[j1].r, mol[j2].r);
      VWrapAll (dr);
      rr = VLenSq (dr);
      if (rr < rrCut) {
        rri = 1. / rr;
        rri3 = Cube (rri);
        fcVal = 48. * rri3 * (rri3 - 0.5) * rri;
        VVSAdd (mol[j1].ra, fcVal, dr);
        VVSAdd (mol[j2].ra, - fcVal, dr);
        uSum += 4. * rri3 * (rri3 - 1.) + 1.;
        virSum += fcVal * rr;
      }
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
    }
  } else {
    DO_MOL VVSAdd (mol[n].rv, 0.5 * deltaT, mol[n].ra);
  }
}


void ApplyBoundaryCond ()
{
  int n;

  DO_MOL VWrapAll (mol[n].r);
}


void InitCoords ()
{
  VecR c, gap;
  int n, nx, ny;

  VDiv (gap, region, initUcell);
  n = 0;
  for (ny = 0; ny < initUcell.y; ny ++) {
    for (nx = 0; nx < initUcell.x; nx ++) {
      VSet (c, nx + 0.5, ny + 0.5);
      VMul (c, c, gap);
      VVSAdd (c, -0.5, region);
      mol[n].r = c;
      ++ n;
    }
  }
}


void InitVels ()
{
  int n;

  VZero (vSum);
  DO_MOL {
    VRand (&mol[n].rv);
    VScale (mol[n].rv, velMag);
    VVAdd (vSum, mol[n].rv);
  }
  DO_MOL VVSAdd (mol[n].rv, - 1. / nMol, vSum);
}


void InitAccels ()
{
  int n;

  DO_MOL VZero (mol[n].ra);
}


void EvalProps ()
{
  real vv, vvMax;
  int n;

  VZero (vSum);
  vvSum = 0.;
  DO_MOL {
    VVAdd (vSum, mol[n].rv);
    vv = VLenSq (mol[n].rv);
    vvSum += vv;
  }
  kinEnergy.val = 0.5 * vvSum / nMol;
  totEnergy.val = kinEnergy.val + uSum / nMol;
  pressure.val = density * (vvSum + virSum) / (nMol * NDIM);
}


void AccumProps (int icode)
{
  if (icode == 0) {
    PropZero (totEnergy);
    PropZero (kinEnergy);
    PropZero (pressure);
  } else if (icode == 1) {
    PropAccum (totEnergy);
    PropAccum (kinEnergy);
    PropAccum (pressure);
  } else if (icode == 2) {
    PropAvg (totEnergy, stepAvg);
    PropAvg (kinEnergy, stepAvg);
    PropAvg (pressure, stepAvg);
  }
}

void PrintSummary (FILE *fp)
{
  int counter=0;
   for( counter=0; counter < nMol; counter++)
	{
	printf("%f, %f, %f, %f\n",mol[counter].r.x, mol[counter].r.y, mol[counter].rv.x, mol[counter].rv.y);
	}
}

// void PrintSummary (FILE *fp)
// {
//   fprintf (fp,
//      "%5d %8.4f %7.4f %7.4f %7.4f %7.4f %7.4f %7.4f %7.4f\n",
//      stepCount, timeNow, VCSum (vSum) / nMol, PropEst (totEnergy),
//      PropEst (kinEnergy), PropEst (pressure));
//   fflush (fp);
// }


#include "in_rand.c"
#include "in_errexit.c"
#include "in_namelist.c"

