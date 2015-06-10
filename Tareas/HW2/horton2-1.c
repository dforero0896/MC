#include <stdio.h>

void main(){
  int dIn;
  double dYd;
  double dFt;
  printf("Enter a distance in inches to be converted to yards and feet: ");
  scanf("%d", &dIn);
  dYd=0.0277778*dIn;
  dFt=0.0833333*dIn;
  printf("The distance in inches is: %d in\n", dIn);
  printf("The distance in yards is: %f yd\n", dYd);
  printf("The distance in feet is: %f ft\n", dFt);
		
}

