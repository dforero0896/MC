#Tercera Tarea
##Primer Punto
```
copo="AIAIA"
orden = 0
'''
if(orden==0):
    t.down() 

    t.forward(300) #A

    t.left(120) #I

    t.forward(300) #A

    t.left(120)#I

    t.forward(300) #A
'''
#elif(orden!=0):
for i in range(orden):
    copo=copo.replace("A", "ADAIADA")
for j in range(len(copo)):
    if (copo[j]=="A"):
        t.forward(100/3**(orden-1))
    elif(copo[j]=="D"):
        t.right(60)
    elif(copo[j]=="I"):
        t.left(120)

t.done()  
```
Se inspiró en el código encontrado en: https://commons.wikimedia.org/wiki/Koch_snowflake#Python
Se explica el objetivo de éste y se hacen pequeñas modificaciones.
##Segundo Punto 


##Tercer Punto
###a.
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

###b.
```
#Se crea el vector para el punto b
x=np.linspace(0., 45., 100)
#Se evalúa la función incluida en numpy.
num=np.sin(x)
#Se evalúa la función definida anteriormete con un número lo suficientemente grande de iteraciones.
mac=numsin(x, 100000)
#Se imprime la diferencia entre las dos funciones.
print abs(num-mac)
#Se imprime la prueba lógica mediante la cual se revisa que todos los elementos en el vector de diferencias sean menor a 0.01.
print abs(num-mac).all < 0.01
#Se crea un ciclo que evalúe la condición anteriormente descrita.
for i in range(1000):
    iteration = i
    mac=numsin(x, i)
    while abs(mac-num).all<0.01:
        print iteration
#Se hace un ciclo que grafique los i primeros órdenes. Ahora se graficará hasta x>45, para ver qué ocurre.
Divergencia, ax=subplots(1, 2, figsize=(20, 7))
ax[0].set_xlim(30, 41)
ax[0].set_ylim(-2, 2)
ax[1].set_xlim(0, 51)
ax[1].set_ylim(-2, 2)
#Se vectoriza la función.
numsin=vectorize(FuncSen)#, excluded=['orden'])
#for i in range(1, 100):
#    ax.plot(L, numsin(L, i))
ax[0].plot(L, numsin(L, 100))
ax[1].plot(L, numsin(L, 100))
ax[0].plot(L, sin(L))
ax[1].plot(L, sin(L))

#Es evidente que la serie comienza a diverger desde x = 35 más o menos, razón por la cual es imposible, para valores mayores a éste
#que el ciclo en el bloque anterior no de respuesta para el número de términos necesarios para que la serie sea lo suficientemente 
#acertada en todo este intervalo. Se muestra en azul la serie de Maclaurin y en rojo la función sen(x) definida en numpy.
#Para solucionar el problema es necesario tomar una serie de Taylor con un centro mucho más cercano al lugar de la divergencia, de manera 
#que el radio de convergencia cubra el intervalo que se quiere visualizar.

#Se genera una función cuyo radio de convergencia incluya el intervalo que se desea.
def FuncSenTaylor(x, orden):
    n=1
    total=0  
    while n<orden:
        a = (-1)**(n-1)*(((x-10*pi)**(2*n-1))/(math.factorial(2*n-1)))
        total+=a
        n += 1
    return total
DivergenciaT, ax=subplots(1, 2, figsize=(20, 7))
ax[0].set_xlim(30, 41)
ax[0].set_ylim(-2, 2)
ax[1].set_xlim(0, 51)
ax[1].set_ylim(-2, 2)
#Se vectoriza la función.
numsinT=vectorize(FuncSenTaylor)#, excluded=['orden'])
#for i in range(1, 100):
#    ax.plot(L, numsin(L, i))
ax[0].plot(L, numsinT(L, 80))
ax[1].plot(L, numsinT(L, 80))
ax[0].plot(L, sin(L))
ax[1].plot(L, sin(L))
#Se ve que, al mover el centro del radio de convergencia de la serie se soluciona el problema de la divergencia en los extremos.
```