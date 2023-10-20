#include "TAD-disperseMatrix.h"
#include <vector>

DisperseMatrix::DisperseMatrix(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            int valor = matriz[i][j];
            if (valor != 0) {
                distintoDeCeros.push_back(valor);
                this->fila.push_back(i);
                this->columnas.push_back(j);
            }
        }
    }
}

DisperseMatrix::DisperseMatrix(std::vector<std::vector<int> > &arreglo)
{

    int fila = arreglo.size();
    int columna = arreglo[0].size();

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (arreglo[i][j] != 0) {
                distintoDeCeros.push_back(arreglo[i][j]);
                this->fila.push_back(i);
                this->columnas.push_back(j);
            }
        }
    }
}

int DisperseMatrix::get(int fila, int columna)
{
    for (int i = 0; i < this->fila.size(); i++) {
        if (this->fila[i] == fila && this->columnas[i] == columna) {
            return distintoDeCeros[i];
        }
    }
    return 0; // cambiar los 2 returns
}


int DisperseMatrix::getMax() {
    int mayor = distintoDeCeros[0];

    for (int i = 1; i < distintoDeCeros.size(); i++) {
        if (distintoDeCeros[i] > mayor) {
            mayor = distintoDeCeros[i];
        }
    }

    return mayor;

}

void DisperseMatrix::assign(int i, int j, int nuevoValor) {
    bool encontrado = false;
    bool eliminado = false;

    for (int index = 0; index < distintoDeCeros.size(); index++) {
        if (fila[index] == i && columnas[index] == j) {
            encontrado = true;

            if (nuevoValor == 0) {
                distintoDeCeros.erase(distintoDeCeros.begin() + index);
                fila.erase(fila.begin() + index);
                columnas.erase(columnas.begin() + index);
                eliminado = true;
            } else {
                distintoDeCeros[index] = nuevoValor;
            }
        }
    }

    if (!encontrado && nuevoValor != 0) {
        distintoDeCeros.push_back(nuevoValor);
        fila.push_back(i);
        columnas.push_back(j);
    }
}

std::vector<int> DisperseMatrix::getRow(int fila)
{
    std::vector<int> filaVector;

    for (int i = 0; i < this->fila.size(); i++) {
        if (this->fila[i] == fila) {
            filaVector.push_back(this->distintoDeCeros[i]);
        }
    }

    return filaVector;
}

std::vector<std::vector<int> > DisperseMatrix::getTranspose(std::vector<std::vector<int> > matriz)
{
    std::vector<std::vector<int> > copiaMatriz(matriz);
    for(int i = 0; i < matriz.size(); i++){
        for(int j = 0; j < matriz[0].size(); j++){
            copiaMatriz[i][j] = matriz[j][i];
        }
    }
    return copiaMatriz;

}

