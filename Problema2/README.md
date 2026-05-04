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
* El compilador debe estar agregado a las variables de entorno (PATH) del sistema.

## Instrucciones de Ejecución
Usando el Script Automático (Recomendado)
Simplemente haz doble clic en el archivo ejecutar.bat. El script:
1. Compilará el código fuente automáticamente.
2. Verificará si hubo errores.
3. Ejecutará el programa en la consola.

