#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estructura para el diccionario de traducción
typedef struct {
    const char *ingles;
    const char *espanol;
} Traduccion;

// Diccionario oficial de las 32 palabras reservadas (ANSI C)
Traduccion diccionario[] = {
    {"auto", "automatico"}, {"break", "romper"}, {"case", "caso"}, {"char", "caracter"},
    {"const", "constante"}, {"continue", "continuar"}, {"default", "defecto"}, {"do", "hacer"},
    {"double", "doble"}, {"else", "sino"}, {"enum", "enumeracion"}, {"extern", "externo"},
    {"float", "flotante"}, {"for", "para"}, {"goto", "ir_a"}, {"if", "si"},
    {"int", "entero"}, {"long", "largo"}, {"register", "registro"}, {"return", "retornar"},
    {"short", "corto"}, {"signed", "con_signo"}, {"sizeof", "tamanio_de"}, {"static", "estatico"},
    {"struct", "estructura"}, {"switch", "segun"}, {"typedef", "definir_tipo"}, {"union", "union"},
    {"unsigned", "sin_signo"}, {"void", "vacio"}, {"volatile", "volatil"}, {"while", "mientras"}
};

int main() {
    FILE *archivo = fopen("programa.txt", "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo 'programa.txt'\n");
        return 1;
    }

    // 1. Carga Dinámica: Medir el tamaño del archivo para asignar memoria exacta
    fseek(archivo, 0, SEEK_END);
    long tamano = ftell(archivo);
    fseek(archivo, 0, SEEK_SET);

    char *codigo = (char *)malloc(tamano + 1);
    if (codigo == NULL) {
        fclose(archivo);
        return 1;
    }

    // Leer el archivo completo a la memoria reservada
    fread(codigo, 1, tamano, archivo);
    codigo[tamano] = '\0';
    fclose(archivo);

    printf("Codigo cargado \n\n");

    // 2. Proceso de verificación y traducción
    char *p = codigo;
    while (*p != '\0') {
        // Identificar inicio de una palabra (letras o guion bajo)
        if (isalpha(*p) || *p == '_') {
            char *inicio = p;
            while (isalnum(*p) || *p == '_') p++;

            int len = p - inicio;
            
            // Extraer la palabra a un buffer temporal
            char *palabra_extraida = (char *)malloc(len + 1);
            strncpy(palabra_extraida, inicio, len);
            palabra_extraida[len] = '\0';

            // Buscar en el diccionario de 32 palabras
            for (int i = 0; i < 32; i++) {
                if (strcmp(palabra_extraida, diccionario[i].ingles) == 0) {
                    printf("Palabra encontrada: %s \t  Traduccion : %s\n", 
                            diccionario[i].ingles, diccionario[i].espanol);
                    break;
                }
            }
            free(palabra_extraida);
        } else {
            p++;
        }
    }

    // 3. Liberar la memoria del código
    free(codigo);
    return 0;
}
