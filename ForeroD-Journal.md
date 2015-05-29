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

A continuación se muestran los resultados de la indagación o "paleontología" que se realizó en el repositorio del curso de Métodos Computacionales. Se usó el comando `git log --before 2013`. Se buscó el segundo *commit* y se obtuvo la fecha y el hash. Se hizo `git checkout hash`. Posteriormente se revisó el repositorio y se vió el syllabus original por medio de `less syllabus.tex` para obtener la informacion requerida.
+ La fecha del segundo commit fue: Sat Jan 5 23:05:56 2013 -0500
+ El tema de la semana 15 del primer curso fue: Semana 15 & M\'etodo de inferencia bayesiana& SQL\\
