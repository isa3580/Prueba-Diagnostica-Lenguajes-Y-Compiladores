#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * Verifica si un carácter representa una pieza de ajedrez válida.
 * Minúsculas para negras (pnbrqk) y mayúsculas para blancas (PNBRQK).
 */
bool esPiezaValida(char c) {
    return strchr("pnbrqkPNBRQK", c) != NULL;
}

/**
 * Valida una cadena en formato FEN.
 * El formato FEN consta de 6 campos separados por espacios.
 */
bool validarFEN(const char *fen) {
    int campoActual = 1;
    int i = 0;

    // --- VALIDACIÓN CAMPO 1: EL TABLERO ---
    // El tablero debe tener 8 filas separadas por '/' y cada fila debe sumar 8 columnas.
    int filas = 0, columnas = 0;
    
    while (fen[i] != ' ' && fen[i] != '\0') {
        char c = fen[i];
        if (c == '/') {
            // Al encontrar '/', verificamos que la fila anterior tenga exactamente 8 casillas
            if (columnas != 8) return false;
            columnas = 0;
            filas++;
        } else if (isdigit(c)) {
            // Si es un número, representa casillas vacías (1 a 8)
            int num = c - '0';
            if (num < 1 || num > 8) return false;
            columnas += num;
        } else if (esPiezaValida(c)) {
            // Si es una letra, es una pieza (ocupa 1 casilla)
            columnas++;
        } else {
            // Cualquier otro carácter es inválido en el campo del tablero
            return false;
        }
        i++;
    }
    // Al final del campo 1, deben haberse contado 7 '/' (8 filas) y la última fila debe sumar 8
    if (columnas != 8 || filas != 7) return false;

    // --- SALTAR ESPACIOS Y VALIDAR CAMPOS 2 AL 6 ---
    while (fen[i] != '\0') {
        // Localizamos el inicio del siguiente campo saltando los espacios
        if (fen[i] == ' ') {
            while (fen[i] == ' ') i++; 
            if (fen[i] == '\0') break;  
            
            campoActual++;
            
            // CAMPO 2: Turno del jugador ('w' o 'b')
            if (campoActual == 2) {
                if (fen[i] != 'w' && fen[i] != 'b') return false;
                // El campo de turno solo debe tener un carácter
                if (fen[i+1] != ' ' && fen[i+1] != '\0') return false; 
            }
            // CAMPO 3: Disponibilidad de enroque (KQkq o '-')
            else if (campoActual == 3) {
                if (fen[i] != '-') {
                    while(fen[i] != ' ' && fen[i] != '\0') {
                        if (!strchr("KQkq", fen[i])) return false;
                        i++;
                    }
                    continue; // El índice ya avanzó dentro del while
                }
            }
            // CAMPO 4: Posibilidad de captura al paso (e.g., "e3" o "-")
            else if (campoActual == 4) {
                if (fen[i] != '-') {
                    // Validar formato de casilla: columna 'a'-'h' y fila '1'-'8'
                    if (fen[i] < 'a' || fen[i] > 'h') return false;
                    if (fen[i+1] < '1' || fen[i+1] > '8') return false;
                }
            }
            // CAMPO 5 y 6: Regla de los 50 movimientos y número de jugada (Relojes)
            else if (campoActual == 5 || campoActual == 6) {
                while(fen[i] != ' ' && fen[i] != '\0') {
                    // Deben ser exclusivamente valores numéricos
                    if (!isdigit(fen[i])) return false;
                    i++;
                }
                continue;
            }
        }
        if (fen[i] != '\0') i++;
    }

    // Un FEN estándar debe contener exactamente los 6 campos
    return (campoActual == 6);
}

int main() {
    char entrada[256];
    printf("Ingrese FEN: ");
    
    // Leemos la entrada del usuario incluyendo espacios
    if (fgets(entrada, sizeof(entrada), stdin)) {
        // Eliminamos el salto de línea al final capturado por fgets
        entrada[strcspn(entrada, "\n")] = 0;
        
        if (validarFEN(entrada)) {
            printf("RESULTADO: VALIDO\n");
        } else {
            printf("RESULTADO: INVALIDO\n");
        }
    }
    return 0;
}