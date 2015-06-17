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
3. http://pi.karmona.com/

#Cuarta clase 3Jun2015

Se pretende graficar el histórico de la tasa de cambio del Dólar en gnuplot.
Se resaltan los comandos `w3m`, `set xdata time` usados a lo largo del ejemplo.

Para hacer fit



```

gnuplot> fit func (x) "archivo.csv" using colx:coly via param1, param2
gnuplot> plot 'galaxies.csv' using 2:3 
gnuplot> replot m*x +b
gnuplot> 
```
Encuentro como ventaja, gigantesca, de gnu sobre python, la facilidad de hacer gráficas simples en 3D.

#Quinta clase 9Jun2015

Tras leer un poco acerca de `make` se ve que es fundamental al trabajar grandes proyectos en los que se actualizan archivos y se hacen contribuciones constantemente.
Todos los archivos son dependientes unos de otros, por lo que se debe hacer un Makefile que, al ejecutarse, actualice automaticamente todos los archivos y permita hacer cosntribuciones desde el punto en que se quedó. 
Con lammps se entra a la capeta src y se ejecuta `make ubuntu_simple`y se espera a que compile.
#Proyecto Final
## 9Jun2015
Para el proyecto final me gustaría hacer un modelo para el movimiento de varios cuerpos como aplicación a la astrofísica. Puede también ser interesante hacer modelos relacionados a sismología. Me inclino por la primera opción. 
Debe ser necesaria la solución de ecuaciones diferenciales, me gustaría hacerlo en `Python`.
## 16Jun2015
Debido a que en clase ya se abordó el tema de los n cuerpos, se ha decidido hacer modelos y animaciones que describan los choques entre ondas o paquetes de ondas. La descripción más a fondo de dicho proyecto se encuentra en la siguiente página: http://www.physics.orst.edu/~rubin/nacphy/ComPhys/PACKETS/. Ahí se ha desarrollado el modelo en C, la idea es realizarlo en Python.
#Sexta clase 10Jun2015

En el Hands-On se requiere graficar un arreglo de gráficas que contengan figuras de Lissajous. La manera mas fácil de inicializar la matriz de ejes es con `Lisa, axes = subplots(5, 5, figsize=(10, 10))` donde se inicializan tanto el objeto figura, como el objeto `axes` que es una matriz de pares de ejes. Luego se hacen dos ciclos con vaiables `i` y `j` de manera que para cada par de ejes se grafique una figura de Lissajous distinta. Para los parámetros ` a` y `b` de las funciones `X` y `Y` se generan enteros aleatorios en un rango de 0 a 100 usando `a=np.random.randint(1, 100)`.
En resumen, el código utilizado fue:
```
t=np.linspace(-pi, 2*pi, 150)
Lisa, axes=subplots(5, 5, figsize=(10, 10))
def X(a, t):
    return np.cos(a*t)
def Y(b, t):
    return np.cos(b*t)
for i in range(5):
    for j in range(5):
        
        a=np.random.randint(1, 100)
        b=np.random.randint(1, 100)
        #print a, b
        axes[i, j].set_xlim(-1, 1)
        axes[i, j].set_ylim(-1, 1)
        axes[i, j].plot(X(a, t), Y(b, t))
        axes[i, j].axis("off")
```
Y se obtuvo la siguiente figura. La complejidad es debida a el alto valor de los parámetros `a` y `b` dado que su límite es 100.
![La figura obtenida](https://raw.githubusercontent.com/dforero0896/MC/master/EjemplosClase/Lissajous.png?raw=tru)

#Octava clase 16Jun2015

Para hacer el ajuste correspondiente al campo magnético en función de la distancia se hizo lo sigueinte:
```

x=(10**-2)*np.asarray([2.3, 2.8,3.2,3.7,4.3])
y=(10**-6)*np.asarray([34745, 19689, 12594, 7982, 5822])
t=(10**-2)*np.linspace(1, 5, 1000)
def B(x, p1):
    return p1/x**3
print type(x)

scatter (x, y)
fitpars, covmat = curve_fit(B, x, y)
plot(t, B(t, fitpars[0]))
print fitpars
```
Y con la cantidad `fitpars[0]` se calcula el momento magético `m` de acuerdo a
```
m=4*np.pi*fitpars[0]/(2*4*np.pi*10**-7)
print m
2.11829496446
```
Para la tabla se ejecutó el siguiente código, tener en cuenta que la primera columna está en centímetros y la segunda columna en micro Teslas:
```

Tabla=np.zeros([100, 2])
xn=(10**-2)*np.linspace(2.3, 4.3, 100)
bn=B(xn, fitpars[0])
Tabla[:, 0]=xn*10**2
Tabla[:, 1]=bn*10**6
print Tabla
[[  2.30000000e+00   3.48203331e+04]
 [  2.32020202e+00   3.39186866e+04]
 [  2.34040404e+00   3.30479034e+04]
 [  2.36060606e+00   3.22066739e+04]
 [  2.38080808e+00   3.13937551e+04]
 [  2.40101010e+00   3.06079658e+04]
 [  2.42121212e+00   2.98481839e+04]
 [  2.44141414e+00   2.91133420e+04]
 [  2.46161616e+00   2.84024253e+04]
 [  2.48181818e+00   2.77144678e+04]
 [  2.50202020e+00   2.70485503e+04]
 [  2.52222222e+00   2.64037971e+04]
 [  2.54242424e+00   2.57793740e+04]
 [  2.56262626e+00   2.51744860e+04]
 [  2.58282828e+00   2.45883751e+04]
 [  2.60303030e+00   2.40203183e+04]
 [  2.62323232e+00   2.34696258e+04]
 [  2.64343434e+00   2.29356391e+04]
 [  2.66363636e+00   2.24177295e+04]
 [  2.68383838e+00   2.19152965e+04]
 [  2.70404040e+00   2.14277662e+04]
 [  2.72424242e+00   2.09545903e+04]
 [  2.74444444e+00   2.04952442e+04]
 [  2.76464646e+00   2.00492264e+04]
 [  2.78484848e+00   1.96160570e+04]
 [  2.80505051e+00   1.91952766e+04]
 [  2.82525253e+00   1.87864454e+04]
 [  2.84545455e+00   1.83891423e+04]
 [  2.86565657e+00   1.80029637e+04]
 [  2.88585859e+00   1.76275231e+04]
 [  2.90606061e+00   1.72624498e+04]
 [  2.92626263e+00   1.69073883e+04]
 [  2.94646465e+00   1.65619979e+04]
 [  2.96666667e+00   1.62259515e+04]
 [  2.98686869e+00   1.58989352e+04]
 [  3.00707071e+00   1.55806478e+04]
 [  3.02727273e+00   1.52707998e+04]
 [  3.04747475e+00   1.49691135e+04]
 [  3.06767677e+00   1.46753219e+04]
 [  3.08787879e+00   1.43891685e+04]
 [  3.10808081e+00   1.41104065e+04]
 [  3.12828283e+00   1.38387989e+04]
 [  3.14848485e+00   1.35741176e+04]
 [  3.16868687e+00   1.33161432e+04]
 [  3.18888889e+00   1.30646647e+04]
 [  3.20909091e+00   1.28194788e+04]
 [  3.22929293e+00   1.25803900e+04]
 [  3.24949495e+00   1.23472099e+04]
 [  3.26969697e+00   1.21197571e+04]
 [  3.28989899e+00   1.18978568e+04]
 [  3.31010101e+00   1.16813407e+04]
 [  3.33030303e+00   1.14700463e+04]
 [  3.35050505e+00   1.12638173e+04]
 [  3.37070707e+00   1.10625028e+04]
 [  3.39090909e+00   1.08659572e+04]
 [  3.41111111e+00   1.06740401e+04]
 [  3.43131313e+00   1.04866162e+04]
 [  3.45151515e+00   1.03035546e+04]
 [  3.47171717e+00   1.01247292e+04]
 [  3.49191919e+00   9.95001819e+03]
 [  3.51212121e+00   9.77930387e+03]
 [  3.53232323e+00   9.61247263e+03]
 [  3.55252525e+00   9.44941469e+03]
 [  3.57272727e+00   9.29002395e+03]
 [  3.59292929e+00   9.13419792e+03]
 [  3.61313131e+00   8.98183749e+03]
 [  3.63333333e+00   8.83284684e+03]
 [  3.65353535e+00   8.68713333e+03]
 [  3.67373737e+00   8.54460734e+03]
 [  3.69393939e+00   8.40518220e+03]
 [  3.71414141e+00   8.26877403e+03]
 [  3.73434343e+00   8.13530166e+03]
 [  3.75454545e+00   8.00468654e+03]
 [  3.77474747e+00   7.87685262e+03]
 [  3.79494949e+00   7.75172626e+03]
 [  3.81515152e+00   7.62923616e+03]
 [  3.83535354e+00   7.50931326e+03]
 [  3.85555556e+00   7.39189065e+03]
 [  3.87575758e+00   7.27690350e+03]
 [  3.89595960e+00   7.16428900e+03]
 [  3.91616162e+00   7.05398627e+03]
 [  3.93636364e+00   6.94593630e+03]
 [  3.95656566e+00   6.84008185e+03]
 [  3.97676768e+00   6.73636745e+03]
 [  3.99696970e+00   6.63473930e+03]
 [  4.01717172e+00   6.53514518e+03]
 [  4.03737374e+00   6.43753448e+03]
 [  4.05757576e+00   6.34185807e+03]
 [  4.07777778e+00   6.24806825e+03]
 [  4.09797980e+00   6.15611877e+03]
 [  4.11818182e+00   6.06596470e+03]
 [  4.13838384e+00   5.97756244e+03]
 [  4.15858586e+00   5.89086964e+03]
 [  4.17878788e+00   5.80584518e+03]
 [  4.19898990e+00   5.72244912e+03]
 [  4.21919192e+00   5.64064266e+03]
 [  4.23939394e+00   5.56038811e+03]
 [  4.25959596e+00   5.48164883e+03]
 [  4.27979798e+00   5.40438925e+03]
 [  4.30000000e+00   5.32857475e+03]]
 
 ```
 
 
