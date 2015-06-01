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


