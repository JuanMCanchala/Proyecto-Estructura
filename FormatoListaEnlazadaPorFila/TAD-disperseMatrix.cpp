#include "TAD-disperseMatrix.h"

/* Implementacion constructores */

DisperseMatrix :: DisperseMatrix(){}

/* Implementacion operaciones */

vector <vector <Nodo>> DisperseMatrix :: rebuild(int **matriz, int fila, int columna){

    int recorrerFilas, recorrerColumnas;
    for(recorrerFilas = 0; recorrerFilas < fila; recorrerFilas++){

        vector <Nodo> listaUno;
        Nodo *tmp = act;

        for(recorrerColumnas = 0; recorrerColumnas < columna; recorrerColumnas++){

            if(matriz[recorrerFilas][recorrerColumnas] != 0){
                Nodo *nuevo = new Nodo;
                nuevo->dato = matriz[recorrerFilas][recorrerColumnas];

                if(tmp == NULL){
                    tmp = nuevo;
                    nuevo->sig = NULL;
                } else {
                    tmp->sig = nuevo;
                    tmp = tmp->sig;
                }

                listaUno.push_back(*nuevo);
            }
        }

        listaEnlazada.push_back(listaUno);
    }

    return listaEnlazada;
}

int DisperseMatrix :: get(int **matriz, int fila, int columna){
    int valor = 0;
    valor = matriz[fila][columna];
    return valor;
}

vector <Nodo> DisperseMatrix :: getRow(int fila){

    vector <Nodo> valoresFila;

    int recorrerColumna;
    for(recorrerColumna = 0; recorrerColumna < listaEnlazada[fila].size(); recorrerColumna++){
        valoresFila.push_back(listaEnlazada[fila][recorrerColumna]);
    }

    return valoresFila;
}

vector <Nodo> DisperseMatrix :: getCol(int columna){

    vector <Nodo> valoresColumna;

    int recorrerFila;
    for(recorrerFila = 0; recorrerFila < 4; recorrerFila++){
        if(listaEnlazada[recorrerFila][columna].dato != 0){
            valoresColumna.push_back(listaEnlazada[recorrerFila][columna]);
        }
    }

    return valoresColumna;
}

int main(){

    int fila = 8;
    int columna = 7;
    int **matriz = new int *[fila];

    matriz[0] = new int[7]{0, 2, 0, 0, 0, 0, 4};
    matriz[1] = new int[7]{0, 8, 9, 0, 0, 1, 0};
    matriz[2] = new int[7]{0, 0, 0, 3, 0, 0, 0};
    matriz[3] = new int[7]{0, 0, 0, 0, 0, 0, 0};
    matriz[4] = new int[7]{5, 0, 0, 0, 0, 6, 0};
    matriz[5] = new int[7]{1, 2, 0, 0, 0, 0, 0};
    matriz[6] = new int[7]{4, 0, 0, 0, 0, 0, 0};
    matriz[7] = new int[7]{0, 0, 7, 0, 0, 11, 0};

    vector <vector <Nodo>> nuevaMatriz;
    DisperseMatrix matrizDispersa;

    matrizDispersa.rebuild(matriz, fila, columna);
    
    vector <Nodo> filaMatriz;
    filaMatriz = matrizDispersa.getCol(0);

    int a;
    for(a = 0; a < filaMatriz.size(); a++){
        cout << filaMatriz[a].dato << " "; 
    }

    return 0;
}