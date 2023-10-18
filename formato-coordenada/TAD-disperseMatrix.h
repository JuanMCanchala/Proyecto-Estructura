/*
 * Autor: Juan Manuel Canchala Jimenez
 * Date: 2 de octubre de 2023
 *
 * Representacion Estructura disperseMatrix
 * Formato: Formato coordenada
 */
/*
front(): retorna una referencia (puntero) al primer elemento.
back(): retorna una referencia (puntero) al  ́ultimo elemento.
push_front(e): agrega un elemento e al inicio de la lista.
push_back(e): agrega un elemento e al final de la lista.
pop_front(): elimina el elemento del inicio de la lista.
pop_back(): elimina el elemento del final de la lista.
empty(): determina si la lista est ́a vac ́ıa.
insert(it, elem), insert(it, n, elem): inserta 1 vez (n veces) el
elemento elem en la posici ́on asociada al iterador it.
erase, remove, reverse, size, sort, . . . : similares a las operaciones
sobre vectores con STL, aunque todas estas funciones est ́an definidas
como m ́etodos en las clase list.
*/
#ifndef DISPERSE_MATRIX
#define DISPERSE_MATRIX

#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class DisperseMatrix
{
private:
    vector<int> distintoDeCeros;
    vector<int> fila; 
    vector<int> columnas; 

public:
    /*Constructores*/
    /*arreglar*/
    DisperseMatrix(int** matriz, int fila, int columna);
    DisperseMatrix(vector<vector<int>>& arreglo);
    DisperseMatrix(DisperseMatrix& a);

    /*Operaciones*/
    vector<vector<int>> rebuild(vector<vector<int>> matriz, int fila, int columna);
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
    vector<vector<int>>getTranspose(vector<vector<int>> matriz); 
    void assign(int i, int j, int nuevoValor);
    void add(vector<vector<int>> matriz);
    void printMatrix(string separacion);
    void productVector(vector<int> vector);
    /*Estaticas*/
    static DisperseMatrix addMatrixLista(vector<DisperseMatrix> &lista);

    /*Operadores sobrecargados*/
    DisperseMatrix operator*(DisperseMatrix &l);
    DisperseMatrix operator+(DisperseMatrix &l);
    bool operator==(DisperseMatrix &l);

};
#endif