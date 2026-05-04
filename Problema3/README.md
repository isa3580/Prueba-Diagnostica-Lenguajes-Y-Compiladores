# Traductor de Palabras Reservadas (C) - Gestión de Memoria Dinámica

Este programa actúa como un analizador léxico básico que identifica las 32 palabras reservadas del estándar ANSI C dentro de un archivo de texto y muestra su traducción al español.

##  Descripción del Problema
El sistema debe leer un código fuente externo (`programa.txt`), identificar qué palabras pertenecen al lenguaje C y proporcionar su significado en español, cumpliendo con los siguientes requisitos técnicos:
1.  **Carga Dinámica:** El programa no usa arreglos de tamaño fijo; mide el tamaño del archivo en tiempo de ejecución y reserva la memoria exacta necesaria.
2.  **Diccionario Estructural:** Utiliza una estructura `typedef struct` para mapear las palabras ingles-español.
3.  **Tokenización:** Escanea el texto carácter por carácter para extraer identificadores válidos.

## Estrategia de Solución
*   **Manejo de Archivos:** Se utiliza `fseek` y `ftell` para determinar el tamaño del archivo antes de la lectura, garantizando eficiencia en el uso de la RAM.
*   **Análisis de Texto:** Se emplean funciones de la librería `<ctype.h>` (`isalpha`, `isalnum`) para distinguir palabras de símbolos o números.
*   **Memoria Dinámica:** Se hace uso de `malloc` para cargar el código completo y para buffers temporales de palabras, asegurando la liberación de la misma con `free` para evitar fugas de memoria.

## Estructura del Proyecto
*   `traductor.c`: Código fuente del analizador.
*   `programa.txt`: Archivo de entrada que contiene el código a analizar.
*   `ejecutar_traductor.bat`: Script para automatizar la compilación y ejecución.

## Requisitos de Instalación
Para compilar y ejecutar este programa, se requiere:
* Un compilador de C (como GCC a través de MinGW).
* Asegurese de estar en la carpeta donde se guardo el archivo

## Instrucciones de Ejecución
Abra el terminal de la computadora en la carpeta donde se encuentra el programa y coloque lo siguientes comandos:

Para compilar:
gcc problema3.c -o problema3.exe

para ejecutar:
problema3.exe


