#!/bin/bash


figlet 1.
 
ninit=$(awk -F","  '{ print $1 }' kepler.csv | wc -l)
nfin=$((ninit-1))
echo Hay $nfin planetas en el archivo.


figlet 2.

awk -F ","  '{ if($2 < 0.01 && $2 != 0) print $2 }' kepler.csv | sed '/^$/d' | wc -l | sed 's/$/ son los planetas con masa menor a una centésima parte de la masa de Júpiter./g'

awk -F ","  '{ if($2 < 0.01 && $2 != 0) print $2 }' kepler.csv | sed '/^$/d' > masasMenores.csv

mass=$(awk -F"," 'NR==1 {print $1}' masasMenores.csv)
awk -v 'var=$mass {if($2==var) print $1' kepler.csv


figlet 3.

sort --field-separator="," --key=6 -n kepler.csv | awk -F"," 'NR==2 {print $1}' | sed 's/$/ es el planeta con menor periodo orbital./g'
