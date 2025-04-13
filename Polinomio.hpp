#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP

#include <vector>

double eval_standard(const std::vector<double>& coef, double x);
double eval_horner(const std::vector<double>& coef, double x);

#endif // POLINOMIO_HPP
