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

