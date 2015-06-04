#Tarea 1

## Primer punto

```
#!/bin/bash
figlet arXiv

echo =====================================
echo Searching the arXiv for the new stuff.
# Se busca en la página de astrofísica.
echo http://arxiv.org/list/astro-ph/new
# Se filtra el código fuente dejando solo las líneas que contengan la palabra a buscar y la palabra Title para devolver el título. Se guerda en un archivo temporal
curl -s http://arxiv.org/list/astro-ph/new | grep -i  $1 | grep Title > archivoConLosTitulos.txt
echo =====================================
echo keyword: $1
echo =====================================
# Se cuentan el número de líneas (Títulos) que coinciden con la palabra buscada.
nlines= wc -l archivoConLosTitulos.txt  | sed 's/archivoConLosTitulos.txt/articles found./g'
# A lo anteriormente obtenido se le cambian los tags de HTML por guiones de manera que quede una lista.
sed 's/<span class="descriptor">Title:<\/span>/-/g' archivoConLosTitulos.txt
#Se elimina el archivo temporal.
rm archivoConLosTitulos.txt
```
## Segundo punto

```
#!/bin/bash


figlet 1.
#Se imprime la primera columna del archivo y se cuentan las líneas, se le resta la línea de encabezado para obtener el número de planetas.
ninit=$(awk -F","  '{ print $1 }' kepler.csv | wc -l)
nfin=$((ninit-1))
echo Hay $nfin planetas en el archivo.


figlet 2.
# Se buscan las masas menores a 0.01 veces la masa de Júpiter  y que además no tuvieran masa igual a cero puesto que parece no tener sentido.
nPlanetas=$(awk -F ","  '{ if($2 < 0.01 && $2 != 0) print $2 }' kepler.csv | sed '/^$/d' | wc -l)
echo Se encontraron $nPlanetas planetas con una masa menor a una centésima parte de la masa de Júpiter
# Se redirigen las masas a un archivo temporal.
awk -F ","  '{ if($2 < 0.01 && $2 != 0) print $2 }' kepler.csv | sed '/^$/d' > masasMenores.csv
# Se recorre el archivo temporal con las masas línea por línea y, para cada línea (masa) se busca el planeta con dicha masa en el archivo principal. Se añade el nombre del planeta a otro archivo temporal.
for i in $(seq 1 $nPlanetas);
do

    mass=$(awk -F","  'NR=='"$i"' {print $1}' masasMenores.csv)
    name=$(awk -v var=$mass -F "," ' {if($2==var) print $1}' kepler.csv)
    echo $name,  >> nombres.tex;
done
echo Los siguientes son sus nombres:
# Se devuelven los nombres.
cat nombres.tex

figlet 3.
# Se utiliza el comando sort para ordenar la columna 6 (números) en orden ascendente y se imprime la segunda línea, dado que la primera contiene encabezados.
sort --field-separator="," --key=6 -n kepler.csv | awk -F"," 'NR==2 {print $1}' | sed 's/$/ es el planeta con menor periodo orbital./g'
# Se remueven los archivos temporales.
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
# Se define como variable a los eventos ocurridos en el año ingresado y se imprime.
history=$(awk -v year=$1 -F "\t" '{if($1 == year) print $2}' worldhistory.tsv)
echo $history

echo ==============================================
# Se calculan los años que comprenden el tiempo a tomar.
yr1=$((2015-$1))
yr2=$((2015-$1+1))
echo $yr1, $yr2

echo LOOK AT THE FOLLOWING STARS:
# Se toma la primera línea del archivo, se modifica dadole un cierto formato y se redirige a un archivo temporal.
awk -F "," '{if(NR==1) print $2, $8, $9}' Hyg.csv| sed 's/hip/HIP_No./g'| sed 's/ra/RA\/°/g'| sed 's/dec/DEC\/°/g' > temporal.csv
#Se buscan en la columna de distancia (en años luz) aquellos valores que estén comprendidos entre los límites anteriormente definidos. Para éstos valores se redirigen las columnas requeridas al archivo temporal.
awk -v y1=$yr1 -v y2=$yr2 -F "," '{if($10>y1 && $10 <y2) print $2, $8, $9}' Hyg.csv >> temporal.csv
# Se imprimen las primeras 6 líneas del archivo temporal (encabezado y cinco estrellas) dandole formato de tabla.
cat temporal.csv | column -t | head -6
# Se elimina el archivo temporal.
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
