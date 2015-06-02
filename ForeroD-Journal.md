#Primera Clase 27May2015
¡Hola Mundo, aquí estoy comenzando el curso de **Métodos Computacionales**-

Herramientas del Curso:
+ git,
+ GitHub,
+ bash,
+ C,
+ y Python.

y los métodos a estudiar son:

1. interpolación,
2. análisis de Fourier,
3. diferenciación e integración numéricas,
4. ecuaciones diferenciales ordinarias,
5. ecuaciones diferenciales parciales,
6. y métodos de Monte Carlo.

Editando online

**Para agregar *commit*s**

Se requiere:


1. git add ForeroD-Journal.md
2. git commit
3. Poner comentario acerca del commit
4. Para subirlo: git push origin master.
5. 

Leer:
+ Pro Git págs: 27-34
  + Como atajo para agregar commit se puede usar *git commit -a -m 'comentario'*
  + Se usa *git commit --amend* para corregir el último commit.
+ Pro Bash Programming 1 - 28
+ Survey Of Computational Physics 1.1 - 1.6

Por revisar: ssh

# Segunda Clase 29May2015

Utilizar variables de bash en awk `awk -v varawk=$varbash` con `varbash` la variable de bash que se desea recuperar.

Para declarar variables mas complejas en bash `var=$(echo $((a+b)))` 

Dado que estoy trabajando en mi propio equipo, fue necesario usar ssh para entrar a compufísica desde mi terminal. Se usó `ssh df.forero10@compufi6.uniandes.edu.co`. La IP de compufísica es: 157.253.160.142 en caso de ser necesaria.


A continuación se muestran los resultados de la indagación o "paleontología" que se realizó en el repositorio del curso de Métodos Computacionales. Se usó el comando `git log --before 2013`. Se buscó el segundo *commit* y se obtuvo la fecha y el hash. Se hizo `git checkout hash`. Posteriormente se revisó el repositorio y se vió el syllabus original por medio de `less syllabus.tex` para obtener la informacion requerida.
+ La fecha del segundo commit fue: Sat Jan 5 23:05:56 2013 -0500
+ El tema de la semana 15 del primer curso fue: Semana 15 & M\'etodo de inferencia bayesiana& SQL\\

# Tercera Clase 2Jun2015

## Expresiones regulares

Se usan para la limpieza de archivos de datos. Ejemplo: joviansatellites.csv 
+ \^ inicio línea
+ \$ final línea
+ \. cualquier caracter
+ .* cuantificador 0 o más
+ .+ cuantificador 1 o más
+ (a|b)
+ \ escape
+ [a-z] rangos, varios elementos
+ \d digitos \D no digitos


## GNU Plot

` gnuplot`


` plot x`


` plot [1:2] x `


` set title "x"`


` set xlabel`


` set ylabel`


` set grid`
``` 
set parametric
plot cos(t), sin(t)
```
`unset parametric`

`splot x**2 + y**2`
Para graficar desde archivo:

```
gnuplot> set datafile separator ","
        plot "joviansatellites.csv" using 2:3
```
donde 2:3 son las columnas de la forma x:y. Se puede agregar `with lines` `with linesp`, `with circles`.

Para definir funciones:
```
gnuplot> quad(x) = x**2
gnuplot> cube(x) = x**3
```
Hacer plots aplicando funciones:
```
gnuplot> plot "joviansatellites.csv" using (cube($colx)):(quad($coly))
```

##Hands-On 2
1. Para una expresión regular que se refiera a los ṕrimeros cuatro caracteres del principio de la línes mas un espacio se debe buscar algo asi: `^.... `.
2. Se agrega a la carpeta de ejemplos el tsv. Se utilizó `^ ` para buscar las lineas al inicio y `: ` para buscar los dos puntos y reemplazarlos por `\t`.
3. 
