#include <iostream>
#include "TAD-disperseMatrix.h"

int main() {
    std::cout << "here";
    // Ejemplo de construcción de una matriz dispersa a partir de una matriz completa
    int matrizCompleta[3][3] = {{0, 0, 0}, {0, 5, 0}, {0, 0, 0}};

    // Convertimos la matriz completa en un puntero a matriz
    int* punteroMatriz[3];
    for (int i = 0; i < 3; i++) {
        punteroMatriz[i] = matrizCompleta[i];
    }

    DisperseMatrix sparseMatrix(punteroMatriz, 3, 3);

    // Ejemplo de obtener un valor en una posición
    int value = sparseMatrix.get(1, 1);
    std::cout << "Valor en la posición (1, 1): " << value << std::endl;

    // Ejemplo de obtener el valor máximo
    int max = sparseMatrix.getMax();
    std::cout << "Valor máximo en la matriz: " << max << std::endl;

    // Ejemplo de asignar un nuevo valor en una posición
    sparseMatrix.assign(1, 1, 10);
    std::cout << "Nuevo valor en la posición (1, 1): " << sparseMatrix.get(1, 1) << std::endl;

    return 0;
}
