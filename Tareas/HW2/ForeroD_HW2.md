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