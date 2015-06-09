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
sed -E 's/\d//g'
xargs -s 500000
sed -E 's/ //g'
```

Es una aproximación al código que se usó.

### d.
