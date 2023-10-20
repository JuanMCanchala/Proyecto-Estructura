/*
 * Autor: Juan Manuel Canchala Jimenez
 * Date: 2 de octubre de 2023
 *
 * Representacion Estructura disperseMatrix
 * Formato: Lista enlazada por fila
 * list<int> distintoDeCeros;
 * list<int> fila;
 * list<int> columna;
*/

#ifndef DISPERSE_MATRIX
#define DISPERSE_MATRIX

#include <vector>
#include <string>
#include <iostream>
#include <list>
using namespace std;

class Nodo {
    public:
    int dato;
    Nodo *sig;
};

class DisperseMatrix {
    private:
        Nodo *act = NULL;
        list <int> fila;
        list <int> columna;
        vector <vector <Nodo>> listaEnlazada;

    public:

        /* Constructores */
        DisperseMatrix();
        DisperseMatrix(int **matriz, int fila, int columna);
        DisperseMatrix(vector <vector <int>> &arreglo);
        DisperseMatrix(DisperseMatrix &a);

        /* Operaciones */
        vector <vector <Nodo>> rebuild(int **matriz, int fila, int columna);
        int get(int **matriz, int fila, int columna);
        vector <Nodo> getRow(int fila);
        list <int> getRowList(int fila);
        vector <Nodo> getCol(int columna);
        list <int> getColList(int columna);
        vector <int> getDisperseRow(int fila);
        list <int> getDisperseRowList(int fila);
        vector <int> getDisperseCol(int columna);
        list <int> getDisperseColList(int columna);
        void printMatrix(string separacion);
        int getMax();
        int getTranspose();

        /* Modificadoras */
        void assign(int i, int j, int nuevoValor);
        void add(vector <vector <int>> matriz);
        void productVector(vector <int> vector);
        
        /* Estaticas */
        static DisperseMatrix addMatrixLista(list <DisperseMatrix> &lista);

        /* Sobrecarga de operadores */
        bool operator * (DisperseMatrix &num);
        bool operator + (DisperseMatrix &num);
        bool operator == (DisperseMatrix &num);
};

#endif