#include <stdio.h>

void main(){
  int type;
  int qty;
  float cost;
  float price1= 3.5;
  float price2= 5.5;
  printf("Please enter the type you want to buy: ");
  scanf("%d", &type);
  printf("Please enter the quantity you want to buy: ");
  scanf("%d", &qty);

  if (type==1){
    cost=qty*price1;
  }
  else if (type==2){
    cost=qty*price2;
  }
  printf("The total cost is %1.2f\n", cost);

}
