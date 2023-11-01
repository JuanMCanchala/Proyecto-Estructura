#include "TAD-disperseMatrix.h"

int main(){

    int **matrizUno = new int *[8];

    for (int i = 0; i < 8; i++) {
        matrizUno[i] = new int[7];
    }

    int matrizDos[8][7] = {
        {0, 2, 0, 0, 0, 0, 4},
        {0, 8, 9, 0, 0, 1, 0},
        {0, 0, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {5, 0, 0, 0, 0, 6, 0},
        {1, 2, 0, 0, 0, 0, 0},
        {4, 0, 0, 0, 0, 0, 0},
        {0, 0, 7, 0, 0, 11, 0}
    };

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            matrizUno[i][j] = matrizDos[i][j];
        }
    }

    vector <vector <int>> matrizTres = {
        {0, 2, 0, 0, 0, 0, 4},
        {0, 8, 9, 0, 0, 1, 0},
        {0, 0, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {5, 0, 0, 0, 0, 6, 0},
        {1, 2, 0, 0, 0, 0, 0},
        {4, 0, 0, 0, 0, 0, 0},
        {0, 0, 7, 0, 0, 11, 0}
    };

    DisperseMatrix matrizDispersa(matrizTres);
    matrizDispersa.assign(1, 2, 0);
    matrizDispersa.printMatrix("-");

    return 0;
}