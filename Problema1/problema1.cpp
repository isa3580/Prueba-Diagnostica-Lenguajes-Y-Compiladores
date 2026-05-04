#include <iostream>
#include <cmath>
#include <iomanip>
#include <chrono>   
#include <fstream>

using namespace std;
using namespace std::chrono; 

// Calcula coeficientes binomiales de forma iterativa (Triángulo de Pascal)
long double* generarCoeficientes(int n) {
    long double* fila = new long double[n + 1]; // Memoria dinámica para n+1 términos
    fila[0] = 1.0; 
    for (int i = 1; i <= n; i++) {
        // Fórmula: C(n,k) basado en el término anterior
        fila[i] = fila[i - 1] * (n - i + 1) / i;
    }
    return fila;
}

// Resuelve la sumatoria de la expansión: Coeficiente * x^(n-i)
long double calcularResultado(long double* coef, int n, long double x) {
    long double suma = 0;
    for (int i = 0; i <= n; i++) {
        suma += coef[i] * pow(x, n - i);
    }
    return suma;
}

// Imprime el desglose paso a paso del cálculo
void mostrarPasos(long double* coef, int n, long double x, long double resultadoTotal) {
    cout << "\n--- Detalles del Calculo ---" << endl;
    for (int i = 0; i <= n; i++) {
        int potencia = n - i;
        long double valorTermino = coef[i] * pow(x, potencia);
        cout << "Paso " << i + 1 << ": " << fixed << setprecision(0) << coef[i] 
             << " * (" << fixed << setprecision(2) << x << "^" << potencia << ")" 
             << " -> " << scientific << setprecision(2) << valorTermino << endl;
    }
    cout << "\nResultado final: " << fixed << setprecision(2) << resultadoTotal << endl;
}

int main() {
    int n;
    long double x;

    cout << "Ingrese n: ";
    cin >> n;
    if (n < 0) return 1;
    
    // Medicion de tiempo de ejecucion
    auto inicioGen = high_resolution_clock::now();
    long double* coeficientes = generarCoeficientes(n);
    auto finGen = high_resolution_clock::now();
    
    duration<double, std::milli> tiempoGen = finGen - inicioGen;

    cout << "Ingrese x: ";
    cin >> x;

    auto inicioRes = high_resolution_clock::now();
    long double resultado = calcularResultado(coeficientes, n, x);
    auto finRes = high_resolution_clock::now();
    
    duration<double, std::milli> tiempoRes = finRes - inicioRes;

    mostrarPasos(coeficientes, n, x, resultado);

    cout << "\n------------------------------------------" << endl;
    cout << "Tiempo Generacion: " << fixed << setprecision(10) << tiempoGen.count() << " ms" << endl;
    cout << "Tiempo Resolucion: " << fixed << setprecision(10) << tiempoRes.count() << " ms" << endl;
    cout << "------------------------------------------" << endl;

    //  Guarda datos en un archivo .txt
    ofstream archivo("resultado_ejecucion.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "C++ | n=" << n << " x=" << x << " | Tiempo Ejecucion: " 
                << fixed << setprecision(10) << tiempoRes.count() << " ms" << endl;
        archivo.close();
    }

    delete[] coeficientes; // Liberación de memoria para evitar fugas
    return 0;
}