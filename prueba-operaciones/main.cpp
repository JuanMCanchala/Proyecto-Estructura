#include <iostream>
#include "TAD-disperseMatrix.h"

//aqui se ejecutaran las pruebas de los constructores y las implementaciones
int main() {
    //primer constructor
    int matrizCompleta[3][3] = {{4, 5, 2}, {8, 5, 5}, {4, 9, 8}};
    int* punteroMatriz[3];
    for (int i = 0; i < 3; i++) {
        punteroMatriz[i] = matrizCompleta[i];
    }
    DisperseMatrix pruebaMatriz(punteroMatriz, 3, 3);

        //segundo constructor
    std::vector<std::vector<int> > matriz;
    std::vector<int> fila1;
    fila1.push_back(2);
    fila1.push_back(2);
    fila1.push_back(2);
    matriz.push_back(fila1);

    std::vector<int> fila2;
    fila2.push_back(1);
    fila2.push_back(1);
    fila2.push_back(1);
    matriz.push_back(fila2);

    std::vector<int> fila3;
    fila3.push_back(3);
    fila3.push_back(3);
    fila3.push_back(3);
    matriz.push_back(fila3);
    DisperseMatrix DisperseMatrix(matriz);

    int value = pruebaMatriz.get(1, 1);
    std::cout << "Valor en la posicion (1, 1): " << value << std::endl;

    int max = pruebaMatriz.getMax();
    std::cout << "Valor maximo en la matriz: " << max << std::endl;

    pruebaMatriz.assign(1, 1, 10);
    std::cout << "Nuevo valor en la posicion (1, 1): " << pruebaMatriz.get(1, 1) << std::endl;

    std::vector<int> getFila = pruebaMatriz.getRow(1);
    std::cout<< "impresion de la fila " << std::endl;
    for(int i = 0; i < getFila.size(); i++){
        std::cout<< getFila[i] << std::endl;
    }

    std::vector<std::vector<int> > transpuesta = DisperseMatrix.getTranspose(matriz);

    std::cout << "matriz transpuesta" << std::endl;
    for(int i = 0; i < transpuesta.size(); i++){
        for(int j=0; j < transpuesta[0].size(); j++){
            std::cout << transpuesta[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}
