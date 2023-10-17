#include "TAD-disperseMatrix.h"

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

int DisperseMatrix::get(int i, int j) {
    for (int index = 0; index < distintoDeCeros.size(); index++) {
        if (fila[index] == i && columnas[index] == j) {
            return distintoDeCeros[index];
        }
    }
    return 0;
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