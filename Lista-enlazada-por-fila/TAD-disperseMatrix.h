/*
 * Autor: Juan Manuel Canchala Jimenez
 * Date: 2 de octubre de 2023
 *
 * Representacion Estructura disperseMatrix
 */

/*correcciones carlos
La opreación getTranspose debería retornar una matriz dispersa
en productVector no estás pasando el vector como referencia. No es buena idea colocarle a las variables nombres iguales a los tipos de datos.
¿cuál es la razón de recorrer todo el vector this->fila si solo necesitas la fila representada por la variable fila?
Algo similar a lo anterior ocurre en la operación get
La operación addMatrizLista debería recibir una lista y no un vector
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
    list<int> distintoDeCeros;
    list<int> fila;
    list<int> columna;

public:
    /*Constructores*/
    DisperseMatrix(int** matriz, int fila, int columna);
    DisperseMatrix(vector<vector<int>>& arreglo);
    DisperseMatrix(DisperseMatrix& a);

    /*Operaciones*/
    vector<vector<int>> rebuild();
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
    int getTranspose(); 
    void assign(int i, int j, int nuevoValor);
    void add(vector<vector<int>> matriz);
    void printMatrix(string separacion);
    void productVector(vector<int> vector);
    /*Estaticas*/
    static DisperseMatrix addMatrixLista(list<DisperseMatrix> &lista);

    /*Operadores sobrecargados*/
    bool operator*(DisperseMatrix &num);
    bool operator+(DisperseMatrix &num);
    bool operator==(DisperseMatrix &num);

};
#endif