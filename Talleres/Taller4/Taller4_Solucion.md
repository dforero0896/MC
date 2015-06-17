#Solución al taller 4

##Punto 1:
A lo largo de todo el documento se tiene que a la izquierda se muestra la interpolación lineal, en el centro la cúbica y a la derecha la polinómica.

```
t=np.linspace(0, 2*pi, 100)
xp=np.asarray([0, pi/2, pi, 3*pi/2, 2*pi])
yp=np.sin(xp)
sCubicoSin = interpolate.interp1d(xp,yp,kind='cubic')
sLinSin = interpolate.interp1d(xp,yp,kind='linear')
interPolSin = interpolate.lagrange(xp, yp)
Fig, ax=subplots(1, 3, figsize=(20, 7))
ax[1].scatter(xp, yp)
ax[1].plot(t, sCubicoSin(t), label="interpolacion")
ax[1].plot(t, sin(t), label="Funcion sen(x)", ls="-.", lw=4)
ax[1].legend()

ax[0].scatter(xp, yp)
ax[0].plot(t, sLinSin(t), label="interpolacion")
ax[0].plot(t, sin(t), label="Funcion sen(x)", ls="-.", lw=4)
ax[0].legend()

ax[2].scatter(xp, yp)
ax[2].plot(t, interPolSin(t), label="interpolacion")
ax[2].plot(t, sin(t), label="Funcion sen(x)", ls="-.", lw=4)
ax[2].legend()

xm=np.asarray([0, pi/4, pi/2, 3*pi/4, pi, 3*pi/2, 5*pi/4, 7*pi/4,  2*pi])
ym=np.sin(xm)
sCubico = interpolate.interp1d(xm,ym,kind='cubic')
sLin = interpolate.interp1d(xm,ym,kind='linear')
interPol = interpolate.lagrange(xm,ym)
Fig, ax=subplots(1, 3, figsize=(20, 7))
ax[1].scatter(xm, ym)
ax[1].plot(t, sCubico(t), label="interpolacion")
ax[1].plot(t, sin(t), label="Funcion sen(x)", ls="-.", lw=4)
ax[1].legend()

ax[0].scatter(xm, ym)
ax[0].plot(t, sLin(t), label="interpolacion")
ax[0].plot(t, sin(t), label="Funcion sen(x)", ls="-.", lw=4)
ax[0].legend()

ax[2].scatter(xm, ym)
ax[2].plot(t, interPol(t), label="interpolacion")
ax[2].plot(t, sin(t), label="Funcion sen(x)", ls="-.", lw=4)
ax[2].legend()

```
```
td=np.linspace(-3, 3, 100)
x=np.asarray([-3, -2, -1, 0, 1, 2, 3])
ypulse=np.asarray([0, 0, 0, 1, 0, 0, 0])
ystep=np.asarray([0, 0, 0, 1, 1, 1, 1])
sLinP = interpolate.interp1d(x,ypulse,kind='linear')
sCubP = interpolate.interp1d(x,ypulse,kind='cubic')
interPolP = interpolate.lagrange(x, ypulse)

fig, ax=subplots(1, 3, figsize=(20, 7))
ax[0].set_ylim(-0.5, 1.5)
ax[1].set_ylim(-0.5, 1.5)
ax[2].set_ylim(-0.5, 1.5)

ax[0].plot(td, sLinP(td))
ax[1].plot(td, sCubP(td))
ax[2].plot(td, interPolP(td))

sLinS = interpolate.interp1d(x,ystep,kind='linear')
sCubS = interpolate.interp1d(x,ystep,kind='cubic')
interPolS = interpolate.lagrange(x, ystep)

fig, ax=subplots(1, 3, figsize=(20, 7))
ax[0].set_ylim(-0.5, 1.5)
ax[1].set_ylim(-0.5, 1.5)
ax[2].set_ylim(-0.5, 1.5)
ax[0].plot(td, sLinS(td))
ax[1].plot(td, sCubS(td))
ax[2].plot(td, interPolS(td))
```
##Punto 3:

Se limpió el archivo online y se copió en Talleres4.csv.
```
data = loadtxt("Taller4.csv", delimiter=',', dtype=None, skiprows=1)
x=data[0:, 0]
y=data[0:, 1]
print len(x)
t=np.linspace(0.138490669327, 4.45641816306, 24)

sCubico=interpolate.interp1d(x, y, kind='cubic')

nuevosDatos=sCubico(t)
print nuevosDatos

fig=figure(figsize=(10, 7))
plot(t, sCubico(t), label="Uniformemente distribuidos")
plot(x, sCubico(x), label="Datos iniciales")
legend()
```
Se ve la comparación del spline con datos uniformemente distribuidos y los datos originales.

