# Problema 2: Validador de Notación FEN (Chess)

Este programa está desarrollado en Lenguaje C y tiene como objetivo validar si una cadena de texto sigue el formato de la Notación Forsyth-Edwards (FEN), utilizada para describir posiciones particulares de un tablero de ajedrez.

## Descripción del Problema
El validador verifica los 6 campos esenciales de una cadena FEN:
1. Disposición de piezas: Valida 8 filas separadas por / y que cada fila sume exactamente 8 casillas.
2. Turno de juego: Verifica si el carácter es w (blancas) o b (negras).
3. Disponibilidad de enroque: Valida combinaciones de K, Q, k, q o el carácter -.
4. Peón al paso: Valida coordenadas de casilla (ej. e3) o -.
5. Reloj de medios movimientos: Valida que sea un número entero.
6. Número de movimiento completo: Valida que sea un número entero.

## Archivos en esta carpeta
* problema2.c: Código fuente en C con la lógica de validación.
* ejecutar.bat: Script de automatización para compilar y ejecutar en Windows.

## Requisitos de Instalación
Para compilar y ejecutar este programa, se requiere:
* Un compilador de C (como GCC a través de MinGW).
* Asegurese de estar en la carpeta donde se guardo el archivo

## Instrucciones de Ejecución
Abra el terminal de la computadora en la carpeta donde se encuentra el programa y coloque lo siguientes comandos:

Para compilar:
gcc problema2.c -o problema2.exe

para ejecutar:
problema2.exe

