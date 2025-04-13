#include "polinomio.hpp"
#include <cmath>

/**
 * @brief Evalúa un polinomio mediante el método estándar.
 * 
 * La fórmula usada es:
 *     P(x) = a₀ + a₁x + a₂x² + ... + aₙxⁿ
 */
double eval_standard(const std::vector<double>& coef, double x) {
    const size_t grado = coef.size() - 1;
    double resultado = 0.0;

    for (size_t i = 0; i <= grado; ++i) {
        resultado += coef[i] * std::pow(x, static_cast<double>(i));
    }

    return resultado;
}

/**
 * @brief Evalúa un polinomio usando el algoritmo de Horner.
 * 
 * P(x) = (...((aₙx + aₙ₋₁)x + aₙ₋₂)x + ... + a₀)
 */
double eval_horner(const std::vector<double>& coef, double x) {
    const size_t grado = coef.size() - 1;
    double resultado = coef[grado];

    for (size_t i = grado; i-- > 0; ) {
        resultado = resultado * x + coef[i];
    }

    return resultado;
}
