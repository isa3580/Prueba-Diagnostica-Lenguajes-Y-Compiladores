# Problema 1: Generación y Evaluación de (x + 1)^n con Memoria Dinámica

Este proyecto resuelve la expansión binomial del polinomio (x + 1)^n y su evaluación posterior, comparando el rendimiento entre Java y C++. Se enfoca en el uso de estructuras dinámicas y la medición precisa de tiempos de ejecución.

## Descripción del Problema
Dado un número entero no negativo n:
1.  Generación: Se calculan los coeficientes del polinomio mediante el Triángulo de Pascal.
2.  Evaluación: Se calcula f(x) para un valor dado, mostrando el desglose paso a paso de cada término.
3.  Persistencia: Los tiempos de ejecución se exportan a un archivo de texto para su posterior análisis comparativo.


## Implementación en Java

1.  Lógica de Coeficientes: Implementa una relación iterativa ($C(n, i) = C(n, i-1) \times \frac{n-i+1}{i}$) para generar los coeficientes binomiales sin recurrir a factoriales, previniendo errores de *overflow*.
2.  Visualización: Muestra en consola la expansión detallada: el coeficiente, la potencia de $x$ y el valor resultante de cada término.
3.  Validación: El programa incluye una validación automática comparando la suma de la expansión contra la función Math.pow(x + 1, n).
4.  Salida de Datos: Utiliza PrintWriter y FileWriter para persistir el cálculo en resultado_ejecucion.txt sin sobrescribir datos previos (modo *append*).

## Implementación en C++ (Dev-C++)
1.  Gestión de Memoria: Se generan los coeficientes utilizando memoria dinámica (new y delete) para optimizar el uso de recursos según el grado n.
2.  Triángulo de Pascal: Implementación eficiente para obtener los coeficientes sin riesgo de desbordamiento por factoriales.
3.  Cálculo por Pasos: Se evalúa f(x) utilizando la función pow(x, i) para cada término, imprimiendo cada paso intermedio en la consola.
4.  Métrica de Rendimiento: Se utiliza la librería (chrono) para medir con alta precisión el tiempo de generación de coeficientes y el tiempo total.
5.  Salida de Datos: Se añade al archivo resultado.txt el identificador del lenguaje y los tiempos de ejecución obtenidos.


## Instrucciones de Ejecución
Siga los pasos a continuación para compilar y ejecutar cada versión de forma manual:

### 1. Ejecución en C++
Abra la terminal en la carpeta raíz del proyecto y ejecute:


# Compilar el código fuente
g++ problema1.cpp -o problema1.exe

# Ejecutar el programa
./problema1.exe

## 2. Ejecución en Java

# Compilar el archivo de clase
javac Problema1.java

# Ejecutar la clase compilada
java Problema1
