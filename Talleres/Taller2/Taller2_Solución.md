# Solución Taller 2
## Primer punto

```
#!/bin/bash
wget https://raw.githubusercontent.com/ComputoCienciasUniandes/MetodosComputacionalesLaboratorio/master/2015-V/actividades/lottery/lottery.csv

     
fecha=$(awk '{if(NR==1) print $0}' lottery.csv)
revisado=$(awk -F "," 'NR>1 {if($1==201415069) print $2}' lottery.csv)

figlet El trabajo hecho el $fecha por 201415069 $1 $revisado .


rm lottery.csv
```

## Segundo punto

```
sed -E 's/\.//g' pgn.dat | sed -E 's/,([0-9])/.\1/g' | sed -E 's/( ([0-9])| \()/\t\1/g' | sed -E 's/\)//g' | sed -E 's/\(/-/g' > pgn.tsv

```
Para organizarlo:
 ```
 sort --field-separator=$'\t' --key=4 -n pgn.tsv | head

```
La Registraduría fue el de menor variación.
