#!/bin/bash


figlet 1.
 
ninit=$(awk -F","  '{ print $1 }' kepler.csv | wc -l)
nfin=$((ninit-1))
echo Hay $nfin planetas en el archivo.


figlet 2.

nPlanetas=$(awk -F ","  '{ if($2 < 0.01 && $2 != 0) print $2 }' kepler.csv | sed '/^$/d' | wc -l)
echo Se encontraron $nPlanetas planetas con una masa menor a una centésima parte de la masa de Júpiter.
awk -F ","  '{ if($2 < 0.01 && $2 != 0) print $2 }' kepler.csv | sed '/^$/d' > masasMenores.csv

for i in $(seq 1 $nPlanetas);
do

    mass=$(awk -F","  'NR=='"$i"' {print $1}' masasMenores.csv)
    name=$(awk -v var=$mass -F "," ' {if($2==var) print $1}' kepler.csv)
    echo $name,  >> nombres.tex;
done
echo Los siguientes son sus nombres:
cat nombres.tex

figlet 3.

sort --field-separator="," --key=6 -n kepler.csv | awk -F"," 'NR==2 {print $1}' | sed 's/$/ es el planeta con menor periodo orbital./g'

rm masasMenores.csv
rm nombres.tex
