#Tarea 1

## Primer punto

```
#!/bin/bash
figlet arXiv

echo =====================================
echo Searching the arXiv for the new stuff.
echo http://arxiv.org/list/astro-ph/new

curl -s http://arxiv.org/list/astro-ph/new | grep -i  $1 | grep Title > archivoConLosTitulos.txt
echo =====================================
echo keyword: $1
echo =====================================
nlines= wc -l archivoConLosTitulos.txt  | sed 's/archivoConLosTitulos.txt/articles found./g'
curl -s http://arxiv.org/list/astro-ph/new | grep -i  $1 | grep Title | sed 's/<span class="descriptor">Title:<\/span>/-/g'
rm archivoConLosTitulos.txt
```
## Segundo punto

```
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
```
## Punto 3

```
#!/bin/bash
echo ==============================================
figlet Stardate
echo ==============================================

figlet $1

history=$(awk -v year=$1 -F "\t" '{if($1 == year) print $2}' worldhistory.tsv)
echo $history

echo ==============================================
yr1=$((2015-$1))
yr2=$((2015-$1+1))
echo $yr1, $yr2

echo LOOK AT THE FOLLOWING STARS:
awk -F "," '{if(NR==1) print $2, $8, $9}' Hyg.csv| sed 's/hip/HIP_No./g'| sed 's/ra/RA\/°/g'| sed 's/dec/DEC\/°/g' > temporal.csv
awk -v y1=$yr1 -v y2=$yr2 -F "," '{if($10>y1 && $10 <y2) print $2, $8, $9}' Hyg.csv >> temporal.csv

cat temporal.csv | column -t | head -6

rm temporal.csv

echo ==============================================
```
## Cuarto punto

```
ssh df.forero10@compufi3.uniandes.edu.co
"Hola Juan." | mail -s "Taller1" j-lizara
exit
sftp df.forero10@compufi3.uniandes.edu.co
cd /usuarios/homenfs7/taller1/
get DANIEL-FELIPE-FORERO-SANCHEZ.png
exit
echo The only real valuable thing is intuition. > lacita.txt
```
