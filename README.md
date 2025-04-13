# Polinomios-EV
# Evaluación de Polinomios: Comparación de Métodos

Este proyecto compara el desempeño computacional entre dos métodos para evaluar polinomios:

- **Método Estándar**: Evalúa cada término como `a_i * x^i`.
- **Método de Horner**: Evalúa el polinomio utilizando una forma factorizada para reducir el número de operaciones.

---

## Autor

**Carlos Jareth Garcia Ramirez**

---

## Requisitos del sistema

- Compilador: `g++` versión 9.0 o superior (se requiere soporte para C++11 o superior).
- Sistema operativo: Windows, Linux o cualquier sistema con soporte para compilación C++ estándar.
- No se requieren bibliotecas externas.

---

## Instrucciones de compilación y ejecución

1. Abre una terminal o consola en el directorio del proyecto.

2. Compila el proyecto con:

   ```bash
   g++ -std=c++11 main.cpp polinomios.cpp -o evaluacion

