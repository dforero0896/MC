# Segunda Tarea

## Primer punto
### a.
```
#!/bin/bash
gnuplot <<EOF

set param
set term dumb
set xrange [-1:1]
set yrange [-1:1]
set size ratio 0.5
unset tics
unset border
unset key
plot $1*cos(t), $1*sin(t)
EOF
```
### b.
 ```
 #!/bin/bash

while [ True ]; do
    clear
    t=$(date +%s)
    r=$(echo "scale=2; (c(0.3*$t/2))^2;" | bc -l)
    gnuplot <<EOF
set param
set term dumb
set xrange [-1:1]
set yrange [-1:1]
set size ratio 0.5
unset tics
unset border
unset key
plot $r*cos(t), $r*sin(t)

EOF
    sleep 1
done
```

##Segundo Punto

###1-1
```
#include <stdio.h>
void main()
{
  printf("Daniel Felipe Forero Sánchez\n");
  printf("cll23c No72-50\n");
  }
```
###1-2
```
#include <stdio.h>
void main(){
  printf("Daniel Felipe Forero Sánchez\ncll 23c 72-50\n");
    }
```
###1-3
```
#include <stdio.h>
void main(){
  printf("\"It\'s freezing in here, \" he said coldly.\n");
}
```

###2-1
```
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
```

###2-2
```
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

```
###2-3

```
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
```
###2-4
```
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
```

## Tercer Punto

### a.
```
#!/bin/bash
letter1=$1
letter2=$2
file=$3
str=$(cat $file)
len=${#str}
lenf=$(($len+1))
echo $len
echo $letter1
echo $letter2

sed "s/$letter1/TEMPORARYONE/g;s/$letter2/TEMPORARYTWO/g;s/TEMPORARYONE/$letter2/g;s/TEMPORARYTWO/$letter1/g" $file

```
### b.
```
#!/bin/bash
inicio=$1
final=$2
long=$(($final - $inicio + 1))
filename=$3
text=$(cat $filename)
echo ${text:$inicio:$long}
```

### c.
```
sed -E 's/Page //g'
sed -E 's/[0-9]//g'
xargs -s 500000
sed -E 's/ //g'
```

Es una aproximación al código que se usó.

### d.
