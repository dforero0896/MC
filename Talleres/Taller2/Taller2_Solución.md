# Solución al Taller 2

## Punto 1

```
#!/bin/bash
wget https://raw.githubusercontent.com/ComputoCienciasUniandes/MetodosComputacionalesLaboratorio/master/2015-V/actividades/lottery/lottery.csv

fecha=$(awk '{if(NR==1) print $0}' lottery.csv)
revisado=$(awk -F "," 'NR>1 {if($1==201415069) print $2}' lottery.csv)

figlet El trabajo hecho el $fecha por 201415069 $revisado .


rm lottery.csv
```

## Punto 2
Los comandos de sed para limpiar el archivo pgn.dat y enviarlo al archivo pgn.tsv son:


```
sed -E 's/\.//g' pgn.dat | sed -E 's/,([0-9])/.\1/g' | sed -E 's/( ([0-9])| \()/\t\1/g' | sed -E 's/\)//g' | sed -E 's/\(/-/g' > pgn.tsv
```

Para averiguar el sector con menor cambio porcentual se usó `sort --field-separator=$'\t' --key=4 -n pgn.tsv | head` obteniendo como resultado la Registraduría, con una variación porcentual de -62.1.

## Punto 3

Las siguientes fueron las expresiones regulares utilizadas (Hecho en gedit):
+ Para eliminar las líneas título: `^[A-Z]+.*$` que se reemplaza con nada.
+ Para eliminar las líneas en blanco: `^\s*$` que se reemplaza con nada. Pero no se elminaron todas.
+ Para terminar de eliminar las líneas en blanco: `\n\n`que se reemplaza con `\n`
+ Para eliminar los paréntesis y su contenido se usó `\(.*\)` y se reemplazó por nada.
+ Para eliminar las comas (,) de los miles se buscó `,` y se reemplazó por nada.
+ Para eliminar los espacios al inicio de cada línea se busca `^ *` y se reemplazan por nada.
+ Para eliminar los espacios que separaban las columnas se busca ` *` y se reemplaza por `,`.
+ Para corregir el error de poner comas en el espacio que separa caracteres de los nombres de los planetas no nombrados, se busca `(\/[1-9][0-9][0-9][1-9]),S` y se reemplaza por `\1_S` dejando lo que originalmente era un espacio como un "_".
+ Para eliminar las "R" de la columna del periodo orbital se busca `(\d)R`y se reemplaza por `\1`.
El archivo saturniansatellites.csv ya está limpio.