#Taller 7 - Caos
*Métodos Computacionales - Laboratorio*

01-Jul-2015 & 03-Jul-2015

## El Atractor de Rössler X 10 ✵

El [sistema de Rössler](https://en.wikipedia.org/wiki/R%C3%B6ssler_attractor) es un sistema de ecuaciones diferenciales lineales que presenta comportamiento caótico. Las ecuaciones que definen al sistema son:

![](https://upload.wikimedia.org/math/7/b/8/7b8101ee4d46234d6ce0db24c1974a7a.png? raw=true =350x).

Siendo a, b y c parámetros.

1. ✵✵ Resuelva las ecuaciones diferenciales para

  ```
  a = b = 0.1,
  c = 14,
  ```
  y t en el intervalo [0,600.].

  Haga una gráfica de la trayectoria en 3D usando  `mpl_toolkits.mplot3d` y otra que sea una proyección sobre el plano `xy`.

  ![](https://github.com/ComputoCienciasUniandes/MetodosComputacionalesLaboratorio/raw/master/2015-V/actividades/talleres/Taller6/3dRossler.png? raw=true =350x)

  ![](https://github.com/ComputoCienciasUniandes/MetodosComputacionalesLaboratorio/raw/master/2015-V/actividades/talleres/Taller6/2dRossler.png? raw=true =350x)

2. ✵✵ A continuación reproduzca el siguiete panel de gráficas (a su vez reproducido del artículo en Wikipedia sobre el sistema). En ello resuelva las ecuaciones diferenciales dejando `a=b=0.1` y resolviendo para el array de tiempos `np.linspace(0,600,10000)` eliminando los 2000 primeros puntos (el transiente).

  ![](https://raw.githubusercontent.com/ComputoCienciasUniandes/MetodosComputacionalesLaboratorio/master/2015-V/actividades/talleres/Taller6/panel.png? raw=true =350x)

3. ✵✵✵ Ahora construya el diagrama de bifurcación para una [sección de Poincaré](https://en.wikipedia.org/wiki/Poincar%C3%A9_map) aproximada por las condiciones: abs(x)<=1 and y >= 0. Tome `a=b=0.1` y modifique `c` entre 1 y 45. Al igual que en el anterior ejercicio elimine 2000 puntos para descartar el transiente.

  ![](https://github.com/ComputoCienciasUniandes/MetodosComputacionalesLaboratorio/raw/master/2015-V/actividades/talleres/Taller6/Rosslerbifurcation.png? raw=true =350x)

4. ✵✵✵ Finalmente haga una animación que de cuenta de la estructura tridimiensional del atractor. **No** utilice `mpl_toolkits.mplot3d`, haga proyecciones sobre los siguientes planos:

  P(θ):={[x,y,z], n=[cos(45º) cos(θ), cos(45º) sin(θ), sin(45º) ] | [x,y,z].n = 0}

  Estos planos están generados por el siguiente par de vectores ortonormales:

  n1(θ) = [-sin(θ), cos(θ), 0]

  n2(θ) = [-cos(45º)cos(θ), -cos(45º)sin(θ), sin(45º)].

  El resultado debe ser similar a [este](https://github.com/ComputoCienciasUniandes/MetodosComputacionalesLaboratorio/raw/master/2015-V/actividades/talleres/Taller6/RosslerAnimation.mp4). Para ello tome los mismos parámetros que en el primer ejercicio duplicando el número de puntos y dejando solo los últimos 40000.

  **Al terminar la clase del viernes ejecute `lottery.sh` para saber si su taller va a ser revisado.**
