/*
 * Autor: Juan Manuel Canchala Jimenez
 *
 * Implemnetacion Estructura DisperseMatrix
 */
#include "TAD-disperseMatrix.h"

/*
Una operación constructora que tome como parámetro una matriz completa representada como un arreglo de
dos dimensiones.
*/
DisperseMatrix::DisperseMatrix(int** matriz, int fila, int columna) {

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (matriz[i][j] != 0) {
                distintoDeCeros.push_back(matriz[i][j]);
                this->fila.push_back(i);
                columnas.push_back(j);
            }
        }
    }
}


/*
Constructor que toma como parametro una matriz representada por un vector de vectores
*/
DisperseMatrix::DisperseMatrix(vector<vector<int>> &arreglo)
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

/*
Constructor que toma como parametro otra instancia de disperseMatrix
*/

DisperseMatrix::DisperseMatrix(DisperseMatrix &a)
{
    this->distintoDeCeros = a.distintoDeCeros;
    this->fila = a.fila;
    this->columnas = a.columnas;
}
/*======================FINAL-CONSTRUCTORES==============================*/

/*
Operación Rebuild.
Entrada: que reconstruya la matriz completa asociada a la instancia de una matriz dispersa.
*/
vector<vector<int>> DisperseMatrix::rebuild(vector<vector<int>> matriz, int fila, int columna)
{

}

/*
Operación get.
Entrada: que permita obtener el valor que está en la posición i, j en la matriz. Si la posición i, j
corresponde a un cero, este valor debe ser retornado.
*/
int DisperseMatrix::get(int fila, int columna)
{
    int ans = 0;
    int valor = 0; 

    for (int i = 0; i < this->fila.size(); i++) {
        if (this->fila[i] == fila && this->columnas[i] == columna) {
            ans = valor;
        }
    }

    return ans;
}

/*
Operación getRow.
Entrada: que permite obtener la fila j de la matriz dispersa como un vector o como una lista
enlazada (se deben considerar ambas variantes).
*/
vector<int> DisperseMatrix::getRow(int fila)
{
    vector<int> filaVector;

    for (int i = 0; i < this->fila.size(); i++) {
        if (this->fila[i] == fila) {
            filaVector.push_back(this->distintoDeCeros[i]);
        }
    }

    return filaVector;
}

/*Operacion getRowList*/
list<int> DisperseMatrix::getRowList(int fila){

}

/*
Operación getCol.
Entrada: que permite obtener la columna j de la matriz dispersa como un vector o como una lista
enlazada (se deben considerar ambas variantes).
*/
vector<int> DisperseMatrix::getCol(int columna)
{

}


/*Operacion getColList*/
list<int> DisperseMatrix::getColList(int columna)
{

}


/*
Operación getDisperseRow.
Entrada: que permite obtener la fila j de la matriz dispersa incluyendo los ceros como
un vector o como una lista enlazada (se deben considerar ambas variantes).
*/
vector<int> DisperseMatrix::getDisperseRow(int fila)
{
}


/*operacion getDisperseRowList*/
list<int> DisperseMatrix::getDisperseRowList(int fila){

}


/*
Operación getDisperseCol.
Entrada: que permite obtener la columna j de la matriz dispersa incluyendo los ceros
como un vector o como una lista enlazada (se deben considerar ambas variantes).
*/
vector<int> DisperseMatrix::getDisperseCol(int columna)
{
}

/*Operacion getDisperseColList*/
list<int> DisperseMatrix::getDisperseColList(int columna)
{

}

/*
Operación getMax.
Entrada: que debe retornar el mayor elemento en la matriz.
*/
int DisperseMatrix::getMax()
{
    int mayor = distintoDeCeros[0];

    for (int i = 1; i < distintoDeCeros.size(); i++) {
        if (distintoDeCeros[i] > mayor) {
            mayor = distintoDeCeros[i];
        }
    }

    return mayor;

}

/*
Operación getTranspose.
Entrada: que construye la matriz dispersa correspondiente a la transpuesta del objeto actual.
*/
vector<vector<int>> DisperseMatrix::getTranspose(vector<vector<int>> matriz)
{
    vector<vector<int>> copiaMatriz(matriz);
    for(int i = 0; i < matriz.size(); i++){
        for(int j = 0; j < matriz[0].size(); j++){
            copiaMatriz[i][j] = matriz[j][i];
        }
    }
    return copiaMatriz;

}

/*
Operación assing.
Entrada: que permite modificar el valor en la posición i, j de la matriz. Es importante resaltar que si el valor anterior es un cero en la matriz original o si el nuevo valor es un cero, se debe modificar la estructura de la matriz dispersa para incluir el nuevo valor o para eliminar la posición que pasa a contener un cero.
*/
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


/*
Operación add.
Entrada: que recibe otra matriz dispersa de iguales dimensiones y le suma al objeto actual la matriz que se recibe como parámetro.
*/
void DisperseMatrix::add(vector<vector<int>> matriz)
{
}

/*
Operación printMatrix.
Entrada: que recibe una cadena de separación e imprime cada fila de la matriz en una línea
con los elementos separados por dicho caracter.
*/
void DisperseMatrix::printMatrix(string separacion)
{
    //revisar ejemplos
}

/*
Operación productVector.
Entrada: que recibe un vector y multiplica el objeto actual por el vector recibido..
*/
void DisperseMatrix::productVector(vector<int> vector)
{
}

/*La operación estática addMatrixList que toman una lista de instancias del TAD DisperseMatrix y retorna el resultado de sumar la lista de matrices recibidas.*/
/*por agregar hasta que se vea en clase como hacerlo*/


/*=========================SOBRECARGAS===================================*/

// Operador + para la suma de dos matrices
DisperseMatrix DisperseMatrix::operator+(DisperseMatrix &l){

}

// Operador * para la multiplicacion de dos matrices
DisperseMatrix DisperseMatrix::operator*(DisperseMatrix &l){
    
}

// Operador == para comprobar si dos matrices son iguales
bool DisperseMatrix::operator==(DisperseMatrix &l){

}