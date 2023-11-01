/*
 * Autor: Juan Manuel Canchala Jimenez
 * Autor: Isabela Gutierrez Reyes
 * Date: 2 de octubre de 2023

 * Representacion Estructura disperseMatrix formato lista enlazada por filas
*/

#ifndef DISPERSE_MATRIX
#define DISPERSE_MATRIX

#include <vector>
#include <string>
#include <iostream>
#include <list>
using namespace std;

class DisperseMatrix {
private:
    vector <list <pair <int, int>>> listaEnlazada;
    int numFilas, numColums;

public:
    /*Constructores*/
    DisperseMatrix();
    DisperseMatrix(int **arreglo, int fila, int columna);                       /* ✔ */
    DisperseMatrix(vector <vector <int>> &vector);                              /* ✔ */
    DisperseMatrix(DisperseMatrix &a);                                          /* ✔ */

    /*Operaciones*/
    vector <vector <int>> rebuild();                                            /* ✔ */
    int get(int fila, int columna);                                             /* ✔ */
    vector <pair <int, int>> getRowVec(int fila);                               /* ✔ */
    list <pair <int, int>> getRowList(int fila);                                /* ✔ */
    vector <pair <int, int>> getColVec(int columna);                            /* ✔ */
    list <pair <int, int>> getColList(int columna);                             /* ✔ */
    vector <pair <int,int>> getDisperseRowVec(int fila);                        /* ✔ */
    list <pair <int, int>> getDisperseRowList(int fila);                        /* ✔ */
    vector <pair <int, int>> getDisperseColVec(int columna);                    /* ✔ */
    list <pair <int, int>> getDisperseColList(int columna);                     /* ✔ */
    int getMax();                                                               /* ✔ */
    DisperseMatrix getTranspose(); 
    void assign(int i, int j, int nuevoValor);                                  /* ✔ */
    void add(DisperseMatrix &nuevaMatriz);
    void printMatrix(string separacion);                                        /* ✔ */
    void productVector(vector <int> &vector);

    /*Estaticas*/
    static DisperseMatrix addMatrixLista(list <DisperseMatrix> &lista);

    /*Operadores sobrecargados*/
    DisperseMatrix operator * (DisperseMatrix &l);
    DisperseMatrix operator + (DisperseMatrix &l);
    bool operator == (DisperseMatrix &l);
};

#endif