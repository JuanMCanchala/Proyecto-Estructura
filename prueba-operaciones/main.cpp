#include <iostream>
#include "TAD-disperseMatrix.h"

int main() {
    int matrizCompleta[3][3] = {{4, 5, 0}, {8, 5, 0}, {1, 9, 8}};
    
    std::vector<std::vector<int>> arreglo = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    DisperseMatrix matriz(arreglo);

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

    std::vector<int> getFila = pruebaMatriz.getRow(2);
    std::cout<< "impresion de la fila ";
    for(int i = 0; i < getFila.size(); i++){
        std::cout<< getFila[i] << std::endl;
    }

    // Obtener la matriz transpuesta utilizando el método getTranspose
    /*std::vector<std::vector<int>> transpuesta = matriz.getTranspose(arreglo);

    // Imprimir la matriz transpuesta para comprobar que funciona correctamente
    std::cout << "Matriz Transpuesta:" << std::endl;
    for (int i = 0; i < transpuesta.size(); ++i) {
        for (int j = 0; j < transpuesta[i].size(); ++j) {
            std::cout << transpuesta[i][j] << " ";
        }
        std::cout << std::endl;
    }*/



    return 0;
}
