#Primer Punto

# La primera sección
A continuación se encontrarán las subsecciones.
## Subsección número 1
1. Se requiere poner una lista numerada
2. Una lista sin numerar
3. Otros items en la siguiente sección.


## Subsección número 2
Dichos items consisten en:
+ Un link.
+ Un trozo de código *inline*.
+ Un trozo de código en bloque.

[Éste es el código que lleva a Google Colombia](http://www.google.com.co)

Además se escribe código correspondiente a la inicialización de un programa matemático en iPython `%pylab inline`.

Por otra parte se ven bloques de código:


```
import numpy as np
import matplotlib.pyplot as plt
```

```
#Primer Punto

# La primera sección
A continuación se encontrarán las subsecciones.
## Subsección número 1
1. Se requiere poner una lista numerada
2. Una lista sin numerar
3. Otros items en la siguiente sección.


## Subsección número 2
Dichos items consisten en:
+ Un link.
+ Un trozo de código *inline*.
+ Un trozo de código en bloque.

[Éste es el código que lleva a Google Colombia](http://www.google.com.co)

Además se escribe código correspondiente a la inicialización de un programa matemático en iPython `%pylab inline`.

Por otra parte se ven bloques de código:


```
import numpy as np
import matplotlib.pyplot as plt
```
```

# Segundo Punto

```
#!/bin/bash
n=1
lim=1000
while [ $lim -ge $n ]
do

    sq=$((n**2))
    echo $n, $sq >> MilEnterosConCuadrados.csv
 let n=$n+1
done

```

#Tercer Punto

```
awk -F"," '{ print $1 + $2 }' MilEnterosConCuadrados.csv
```
