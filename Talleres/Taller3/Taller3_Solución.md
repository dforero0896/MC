#Taller 3
## Primer punto
```
#!/bin/bash

for file in $(ls *.c);
do
    echo "#Nombre de archivo: $file" >> archivos.md
    echo '```' >> archivos.md
    cat $file >> archivos.md
    echo '```' >> archivos.md

done
```

##Segundo Punto

```
#!/bin/bash
count=1
for file in $(ls *.c);
do
 if [ $count -le 30 ];
then
    
    name=$(echo $file)
    newname=$(echo $name | sed 's/\.c/.out/')
    gcc $file -o $newname
    grep -A 1 Example $file
    ./$newname
    count=$(($count+1))
    read -p "Presione cualquier tecla para continuar... " -n1 -s

else
    break
    
fi
done

```
