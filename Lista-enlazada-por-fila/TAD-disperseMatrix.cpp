/*
 * Autor: Juan Manuel Canchala Jimenez
 * Autor: Isabela Gutierrez Reyes
 *
 * Implemnetacion Estructura DisperseMatrix
*/

#include "TAD-disperseMatrix.h"

/* Implementacion constructores */

/* Implementacion operaciones */

int DisperseMatrix :: get(int fila, int columna){

    int ans = 0;
    list <pair <int, int>> :: iterator it;

    for(it = listaEnlazada[fila].begin(); it != listaEnlazada[fila].end(); it++){
        if(it->second == columna){
            ans = it->first;
        }
    }

    return ans;
}

vector <int> DisperseMatrix :: getRow(int fila){

    vector <int> vectorFila;
    list <pair <int, int>> :: iterator it;

    for(it = listaEnlazada[fila].begin(); it != listaEnlazada[fila].end(); it++){
        vectorFila.push_back(it->first);
    }

    return vectorFila;
}

list <int> DisperseMatrix :: getRowList(int fila){

    list <int> listaFila;
    list <pair <int, int>> :: iterator it;

    for(it = listaEnlazada[fila].begin(); it != listaEnlazada[fila].end(); it++){
        listaFila.push_back(it->first);
    }

    return listaFila;
}

vector <int> DisperseMatrix :: getCol(int columna){

    vector <int> vectorColumna;

    int fila, posicion;
    list <pair <int, int>> :: iterator it;

    for(fila = 0; fila < listaEnlazada.size(); fila++){
        posicion = 0;
        for(it = listaEnlazada[fila].begin(); it != listaEnlazada[fila].end(); it++){
            if(posicion == columna){
                vectorColumna.push_back(it->first);
            }
            posicion++;
        }
    }

    return vectorColumna;
}

list <int> DisperseMatrix :: getColList(int columna){

    list <int> listaColumna;

    int fila, posicion;
    list <pair <int, int>> :: iterator it;

    for(fila = 0; fila < listaEnlazada.size(); fila++){
        posicion = 0;
        for(it = listaEnlazada[fila].begin(); it != listaEnlazada[fila].end(); it++){
            if(posicion == columna){
                listaColumna.push_back(it->first);
            }
            posicion++;
        }
    }

    return listaColumna;
}