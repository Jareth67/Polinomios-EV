#include "polinomio.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

const int NUM_PRUEBAS = 1000;
const int MIN_GRADO = 10;
const int MAX_GRADO = 1000;
const int INCREMENTO = 10;
const double X_VALOR = 1.5;

/**
 * @brief Genera un vector de coeficientes aleatorios para un polinomio.
 * 
 * @param grado Grado del polinomio
 * @return std::vector<double> Vector con coeficientes aleatorios en [-100, 100]
 */
std::vector<double> generar_coeficientes(int grado) {
    std::vector<double> coef(grado + 1);
    for (int i = 0; i <= grado; ++i) {
        coef[i] = -100 + static_cast<double>(rand()) / RAND_MAX * 200; // [-100, 100]
    }
    return coef;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    std::ofstream salida("resultados_tiempos.csv");
    salida << "Grado,Tiempo_Estandar(ms),Tiempo_Horner(ms)\n";

    for (int grado = MIN_GRADO; grado <= MAX_GRADO; grado += INCREMENTO) {
        double suma_estandar = 0.0;
        double suma_horner = 0.0;

        for (int i = 0; i < NUM_PRUEBAS; ++i) {
            std::vector<double> coef = generar_coeficientes(grado);

            // Método estándar
            auto inicio1 = std::chrono::high_resolution_clock::now();
            eval_standard(coef, X_VALOR);
            auto fin1 = std::chrono::high_resolution_clock::now();
            suma_estandar += std::chrono::duration<double, std::micro>(fin1 - inicio1).count();

            // Método de Horner
            auto inicio2 = std::chrono::high_resolution_clock::now();
            eval_horner(coef, X_VALOR);
            auto fin2 = std::chrono::high_resolution_clock::now();
            suma_horner += std::chrono::duration<double, std::micro>(fin2 - inicio2).count();
        }

        double promedio_estandar = suma_estandar / NUM_PRUEBAS;
        double promedio_horner = suma_horner / NUM_PRUEBAS;

        salida << grado << "," << promedio_estandar << "," << promedio_horner << "\n";
        std::cout << "Grado: " << grado
                  << " | Estándar: " << promedio_estandar << " µs"
                  << " | Horner: " << promedio_horner << " µs\n";
    }

    salida.close();
    return 0;
}
