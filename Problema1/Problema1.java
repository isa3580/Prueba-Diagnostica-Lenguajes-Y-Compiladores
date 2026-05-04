/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package problema1;

/**
 *
 * @author 9isab
 */

import java.util.Scanner;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Locale;

public class Problema1 {

    public static void main(String[] args) {
        // Configura el escáner para reconocer el punto (.) como separador decimal
        Scanner sc = new Scanner(System.in).useLocale(Locale.US);

        System.out.print("Ingrese el exponente (n): ");
        int n = sc.nextInt();
        
        if (n < 0) return;

        //  Primero calculamos todos los coeficientes de la fila 'n' del Triángulo de Pascal
        double[] coef = generarCoeficientes(n);

        System.out.print("Ingrese el valor de x: ");
        double x = sc.nextDouble();

        //  Calculamos el resultado final sumando cada término 
        double sumaTotal = calcularResultadoPuro(coef, n, x);

        // Muestra la operación término a término
        mostrarPasos(coef, n, x, sumaTotal);

        // Guarda el resultado obtenido en un archivo de texto
        guardarResultado(n, x, sumaTotal);
    }

    /**
     * Genera los coeficientes binomiales para (x + 1)^n.
     * Utiliza una propiedad iterativa para evitar calcular factoriales, 
     * lo cual previene errores de desbordamiento (overflow).
     */
    public static double[] generarCoeficientes(int n) {
        double[] coef = new double[n + 1];
        coef[0] = 1; // El primer coeficiente C(n, 0) siempre es 1
        
        for (int i = 1; i <= n; i++) {
            // Relación: Coeficiente actual = Coeficiente anterior * (n - i + 1) / i
            coef[i] = coef[i - 1] * (n - i + 1) / i;
        }
        return coef;
    }

    /**
     * Aplica la fórmula: f(x) = Σ [ C(n, i) * x^(n-i) * 1^i ]
     * Como el segundo término del binomio es 1, su potencia siempre es 1 y se omite.
     */
    public static double calcularResultadoPuro(double[] coef, int n, double x) {
        double suma = 0;
        for (int i = 0; i <= n; i++) {
            // coef[i] es el número combinatorio, Math.pow gestiona la potencia de x
            suma += coef[i] * Math.pow(x, n - i);
        }
        return suma;
    }

    /**
     * Imprime la representación visual de la expansión del binomio.
     */
    public static void mostrarPasos(double[] coef, int n, double x, double sumaTotal) {
        System.out.println("\n--- Expansión del Binomio ---");
        for (int i = 0; i <= n; i++) {
            int pot = n - i;
            double termino = coef[i] * Math.pow(x, pot);
            // Imprime: Coeficiente * (x ^ potencia)
            System.out.printf("Término %d: %.0f * (%.2f^%d) = %.2e\n", i + 1, coef[i], x, pot, termino);
        }
        System.out.printf("\nResultado Final de la Suma: %.2f\n", sumaTotal);
        // Comparación con la función directa de Java para validar la lógica
        System.out.printf("Validación con Math.pow(x+1, n): %.2f\n", Math.pow(x + 1, n));
    }

    /**
     * Escribe el resultado en un archivo externo sin borrar los registros previos.
     */
    public static void guardarResultado(int n, double x, double resultado) {
        try (PrintWriter out = new PrintWriter(new FileWriter("resultado_ejecucion.txt", true))) {
            out.printf("Cálculo: (%.2f + 1)^%d = %.4f\n", x, n, resultado);
            System.out.println("\n Datos exportados exitosamente.");
        } catch (Exception e) {
            System.err.println("Error de escritura: " + e.getMessage());
        }
    }
}