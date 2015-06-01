#!/bin/bash
echo Se calculará el número de planetas extrasolares en el archivo. \\n
ninit=$(awk -F","  '{ print $1 }' kepler.csv | wc -l)
nfin=$((ninit-1))
echo Hay $nfin planetas en el archivo.

echo Se calculará ahora el número de planetas con una masa menor a una centésima de la masa de Júpiter

#nmasa= $(awk -F ","  '{ if($2 < 0.01 && $2 != 0) print $2 }' kepler.csv | sed '/^$/d' | wc -l)

echo Se devolverá el nombre del planeta con menor periodo orbital.
sort --field-separator="," --key=6 -n kepler.csv | awk -F"," 'NR==2 {print $1}'
echo es el planeta con menor periodo orbital. 
