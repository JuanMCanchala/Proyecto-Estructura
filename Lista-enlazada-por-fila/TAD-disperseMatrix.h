/*
 * Autor: Juan Manuel Canchala Jimenez
 * Date: 2 de octubre de 2023
 *
 * Representacion Estructura disperseMatrix
 */


#ifndef DISPERSE_MATRIX
#define DISPERSE_MATRIX

#include <vector>
#include <string>
#include <iostream>
#include <list>
using namespace std;

class DisperseMatrix
{
private:
    vector<list<int> > filas;
    int numFilas;
    int numColums;

public:
    /*Constructores*/
    DisperseMatrix(int** matriz, int fila, int columna);
    DisperseMatrix(vector<vector<int>>& arreglo);
    DisperseMatrix(DisperseMatrix& a);

    /*Operaciones*/
    vector<vector<int> > rebuild();
    int get(int fila, int columna);
    vector<int> getRow(int fila);
    list<int> getRowList(int fila);
    vector<int> getCol(int columna);
    list<int> getColList(int columna);
    vector<int> getDisperseRow(int fila);
    list<int> getDisperseRowList(int fila);
    vector<int> getDisperseCol(int columna);
    list<int> getDisperseColList(int columna);
    int getMax();
    DisperseMatrix getTranspose(); 
    void assign(int i, int j, int nuevoValor);
    void add(DisperseMatrix);
    void printMatrix(string separacion);
    void productVector(vector<int> &vector);

    /*Estaticas*/
    static DisperseMatrix addMatrixLista(list<DisperseMatrix> &lista);

    /*Operadores sobrecargados*/
    DisperseMatrix operator*(DisperseMatrix &l);
    DisperseMatrix operator+(DisperseMatrix &l);
    bool operator==(DisperseMatrix &l);

};
#endif