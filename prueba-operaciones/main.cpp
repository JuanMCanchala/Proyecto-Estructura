#include <iostream>
#include "TAD-disperseMatrix.h"

int main() {
    std::cout << "here";
    int matrizCompleta[3][3] = {{0, 0, 0}, {0, 5, 0}, {0, 0, 0}};

    int* punteroMatriz[3];
    for (int i = 0; i < 3; i++) {
        punteroMatriz[i] = matrizCompleta[i];
    }

    DisperseMatrix pruebaMatriz(punteroMatriz, 3, 3);

    int value = pruebaMatriz.get(1, 1);
    std::cout << "Valor en la posición (1, 1): " << value << std::endl;

    int max = pruebaMatriz.getMax();
    std::cout << "Valor máximo en la matriz: " << max << std::endl;

    pruebaMatriz.assign(1, 1, 10);
    std::cout << "Nuevo valor en la posición (1, 1): " << pruebaMatriz.get(1, 1) << std::endl;

    return 0;
}
