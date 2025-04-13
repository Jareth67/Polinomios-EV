# Polinomios-EV




---

# Evaluación de Polinomios: Comparación de Métodos

Este proyecto compara el desempeño computacional entre dos métodos para evaluar polinomios:

- **Método Estándar**: Evalúa cada término como `a_i * x^i`.
- **Método de Horner**: Evalúa el polinomio utilizando una forma factorizada para reducir el número de operaciones.

---

## Autor

**Carlos Jareth Garcia Ramirez**

---

## Requisitos del sistema

- **Compilador:** `g++` versión 9.0 o superior (requiere soporte para C++11 o superior)
- **Sistema operativo:** Windows, Linux o cualquier sistema con soporte para compilación C++ estándar
- **Bibliotecas externas:** Ninguna

---

## Instrucciones de compilación y ejecución

1. Abre una terminal o consola en el directorio del proyecto.

2. Compila el proyecto con el siguiente comando:

    ```bash
    g++ -std=c++11 main.cpp polinomios.cpp -o evaluacion
    ```

3. Ejecuta el programa:

   ```bash
    ./evaluacion
    ```

    Esto generará un archivo llamado `resultados_tiempos.csv` con los tiempos promedio de evaluación para cada método y cada grado.

---

## Descripción de los algoritmos

### Método Estándar

Calcula cada término del polinomio directamente como:
P(x) = a₀ + a₁x + a₂x² + ... + aₙxⁿ


Este enfoque implica múltiples llamadas a la función `pow(x, i)` y `n` multiplicaciones. Su complejidad es aproximadamente **O(n²)** si se considera el costo de `pow()` como lineal.

---

### Método de Horner

Reestructura el polinomio en forma factorizada para evaluarlo eficientemente:
P(x) = (...((aₙx + aₙ₋₁)x + aₙ₋₂)x + ... + a₀)


Este método requiere únicamente `n` multiplicaciones y `n` sumas. Su complejidad es **O(n)**.

---

## Resultados experimentales y gráfica comparativa

Se evaluaron polinomios de grados desde 10 hasta 1000 (con incrementos de 10).  
Para cada grado, se generaron coeficientes aleatorios y se calcularon los tiempos promedio de evaluación con ambos métodos, repitiendo el experimento 1000 veces por caso.

Los resultados se guardaron en el archivo [Descargar resultados_tiempos.csv](TiemposCSV/resultados_tiempos.csv)
`.  
Pude generar una gráfica a partir de este archivo para comparar visualmente el rendimiento.
## Gráfica comparativa

![Comparación de métodos](ResultadosGRAFICA/Grafica.PNG)

---

## Análisis de resultados

- El método de **Horner** es consistentemente más rápido en todos los casos.
- A medida que crece el grado del polinomio, la diferencia de tiempos entre ambos métodos se hace más pronunciada.
- Esto concuerda con la **complejidad teórica** de cada algoritmo:  
  - Estándar: hasta O(n²) por uso de potencias  
  - Horner: O(n) exacto, sin uso de `pow`

---





## Conclusiones

- Horner es **claramente superior** en términos de eficiencia computacional.
- La evaluación estándar es simple pero se vuelve ineficiente rápidamente conforme crece el grado.
- Este experimento valida de forma práctica el análisis de complejidad de ambos métodos.
- Para aplicaciones reales, Horner debe ser el método preferido.

---

## Datos experimentales

Se incluye el archivo resultados_tiempos.csv con los tiempos promedios de evaluación para cada grado.  
Este archivo fue generado automáticamente al ejecutar el programa.

---

## Documentación del código

Todo el código fuente está **comentado con claridad**.  
Cada función está documentada utilizando el formato `@brief` compatible con [Doxygen].


