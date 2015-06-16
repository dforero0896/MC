#Tercera Tarea
##Primer Punto


##Segundo Punto 


##Tercer Punto
```
#Se importan los paquetes necesarias.
%pylab inline
import math
#Se crea un vector de abscisas
L=np.linspace(-pi, 100, 1000)
#Se define el estilo XKCD
plt.xkcd()
#Se define una función que calcula la serie de Maclaurin para sen(x) a manera de 
#prueba y comparación.
def FuncSenFactorial(x, orden):
    n=1
    total=0  
    while n<orden:
        a = (-1)**(n-1)*((x**(2*n-1))/(math.factorial(2*n-1)))
        total+=a
        n += 1
    return total
#Se hace un ciclo que grafique los i primeros órdenes.
Funcsenfac, ax=subplots(1, 1, figsize=(10, 7))
ax.set_xlim(0, 20)
ax.set_ylim(-2, 2)
for i in range(2, 30):
   ax.plot(L, FuncSenFactorial(L, i)) 
#Se define una función que calcula la serie de Maclaurin para sin(x) sin usar
#la función factorial.
def FuncSen(x, orden):
    term=x
    total=term
    for n in range(1, orden):
        term*=-x**2/((2*n+1)*(2*n))
        total+=term
    return total
#Se hace un ciclo que grafique los i primeros órdenes.
Funcsen, ax=subplots(1, 1, figsize=(10, 7))
ax.set_xlim(0, 20)
ax.set_ylim(-2, 2)
#Se vectoriza la función.
numsin=vectorize(FuncSen)#, excluded=['orden'])
for i in range(1, 100):
    ax.plot(L, numsin(L, i))
``` 
Nótese que se ha cambiado la función encontrada en el libro de Landau por la encontrada en el siguiente foro : http://stackoverflow.com/questions/19990274/sin-with-taylor-series-in-python.
Soluciona el problema que se presentaba: División entre cero.
