#include <stdio.h>
#include <math.h>
void main(){
  float pay;
  float hours;
  int residual;
  int dollars;
  float avgpay;
  printf("Please enter your weekly pay in dollars: ");
  scanf("%f", &pay);
  printf("Please enter the hours worked weekly: ");
  scanf("%f", &hours);

  avgpay=pay/hours;
  dollars=(int)avgpay;
  residual=(avgpay-dollars)*100;
  printf("Your average hourly pay rate is %d dollars and %d cents.\n", dollars, residual);
    
  
}
