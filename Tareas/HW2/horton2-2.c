#include <stdio.h>

void main(){
  float lenFt;
  float widIn;
  double widYd;
  double lenYd;
  double areaYd;
  printf("Enter the length of a room in feet: ");
  scanf("%f0.00", &lenFt);
  printf("Enter the width of a room in inches: ");
  scanf("%f0.00", &widIn);
  lenYd=lenFt/3;
  widYd=0.0277778*widIn;
  areaYd=widYd*lenYd;

   printf("The area in square yards is: %1.2f yd^2\n", areaYd);

		
}
