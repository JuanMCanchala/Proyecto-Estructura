#ifndef TAD_DISPERSEMATRIX_H
#define TAD_DISPERSEMATRIX_H

#include <vector>

class DisperseMatrix {
private:
    std::vector<int> distintoDeCeros;
    std::vector<int> fila;
    std::vector<int> columnas;
public:
    DisperseMatrix(int** matriz, int filas, int columnas);
    int get(int i, int j);
    int getMax();
    void assign(int i, int j, int nuevoValor);
};

#endif