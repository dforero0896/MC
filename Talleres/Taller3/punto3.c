
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double gaussrand(void);

int main(void)
{
  double x;
  double y;
  double z;
  int num = 1000;
  int i = 1;
  double norm;
  for(; i <= num; i++);{
    x=gaussrand();
    y=gaussrand();
    z=gaussrand();
    norm=sqrt(x*x + y*y + z*z);
    x=x/norm;
    y=y/norm;
    z=z/norm;
    printf("%f, %f, %f\n", x, y, z);}
}


double gaussrand()
{
	static double V1, V2, S;
	static int phase = 0;
	double X;

	if(phase == 0) {
		do {
			double U1 = (double)rand() / RAND_MAX;
			double U2 = (double)rand() / RAND_MAX;

			V1 = 2 * U1 - 1;
			V2 = 2 * U2 - 1;
			S = V1 * V1 + V2 * V2;
			} while(S >= 1 || S == 0);

		X = V1 * sqrt(-2 * log(S) / S);
	} else
		X = V2 * sqrt(-2 * log(S) / S);

	phase = 1 - phase;

	return X;
}
