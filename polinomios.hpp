#ifndef POLINOMIO_HPP_INCLUDED
#define POLINOMIO_HPP_INCLUDED

#include <vector>

// Evalúa P(x) = aₙ xⁿ + … + a₁ x + a₀ con el método estándar
double eval_standard(const std::vector<double>& coef, double x);

// Evalúa P(x) con el método de Horner:
// (((aₙ x + aₙ₋₁) x + aₙ₋₂) … ) x + a₀
double eval_horner(const std::vector<double>& coef, double x);

#endif // POLINOMIO_HPP_INCLUDED

