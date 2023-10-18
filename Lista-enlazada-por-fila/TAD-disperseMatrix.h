/*
 * Autor: Juan Manuel Canchala Jimenez
 * Date: 2 de octubre de 2023
 * 
 * Representacion Estructura disperseMatrix
 * Formato: Lista enlazada por fila
 *  list<int> distintoDeCeros;
 *  list<int> fila;
 * list<int> columna;
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
        list <int> distintoDeCeros;
        list <int> fila;
        list <int> columna;

    public:
        /* Constructores */
        DisperseMatrix(int **matriz, int fila, int columna);
        DisperseMatrix(vector <vector <int>> &arreglo);
        DisperseMatrix(DisperseMatrix &a);  /*Deberia de pasar por valor porque es una copia y no por referencia para que no sean modificables*/

        /* Operaciones */
        list <list <int>> rebuild(vector<vector<int>> matriz, int fila, int columna); /*Retorna una lista no un vector*/
        int get(int fila, int columna);
        vector <int> getRow(int fila);
        list <int> getRowList(int fila);
        vector <int> getCol(int columna);
        list <int> getColList(int columna);
        vector <int> getDisperseRow(int fila);
        list <int> getDisperseRowList(int fila);
        vector <int> getDisperseCol(int columna);
        list <int> getDisperseColList(int columna);
        void printMatrix(string separacion); /*Es un solo caracter (tipo char) o pueden ser varios(tipo string)*/
        int getMax();
        int getTranspose();

        /* Modificadoras */
        void assign(int i, int j, int nuevoValor);
        void add(vector<vector<int>> matriz);
        void productVector(vector<int> vector);
        
        /*Estaticas*/
        static DisperseMatrix addMatrixLista(list<DisperseMatrix> &lista);

        /*Operadores sobrecargados*/
        bool operator*(DisperseMatrix &num);
        bool operator+(DisperseMatrix &num);
        bool operator==(DisperseMatrix &num);
};

#endif