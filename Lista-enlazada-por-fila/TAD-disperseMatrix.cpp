#include "TAD-disperseMatrix.h"

/*
 * Autor: Juan Manuel Canchala Jimenez
 * Autor: Isabela Gutierrez Reyes
 * Date: 2 de octubre de 2023
 
 * Implementacion Estructura disperseMatrix formato lista enlazada por filas
*/

/* Implementacion constructores */

DisperseMatrix :: DisperseMatrix(){}

DisperseMatrix :: DisperseMatrix(int **arreglo, int fila, int columna){

    numFilas = fila;
    numColums = columna;

    list <pair <int, int>> nuevaLista;

    int recorrerFilas, recorrerColumnas;
    for(recorrerFilas = 0; recorrerFilas < numFilas; recorrerFilas++){
        for(recorrerColumnas = 0; recorrerColumnas < numColums; recorrerColumnas++){
            if(arreglo[recorrerFilas][recorrerColumnas] != 0){
                pair <int, int> pareja(arreglo[recorrerFilas][recorrerColumnas], recorrerColumnas);
                nuevaLista.push_back(pareja);
            }
        }

        this->listaEnlazada.push_back(nuevaLista);
        nuevaLista.clear();
    }
}   

DisperseMatrix :: DisperseMatrix(vector <vector <int>> &vector){

    numFilas = vector.size();
    numColums = vector[0].size();

    list <pair <int, int>> nuevaLista;

    int recorrerFila, recorrerColumna;
    for(recorrerFila = 0; recorrerFila < numFilas; recorrerFila++){
        for(recorrerColumna = 0; recorrerColumna < numColums; recorrerColumna++){
            if(vector[recorrerFila][recorrerColumna] != 0){
                pair <int, int> pareja(vector[recorrerFila][recorrerColumna], recorrerColumna);
                nuevaLista.push_back(pareja);
            }
        }

        listaEnlazada.push_back(nuevaLista);
        nuevaLista.clear();
    }
}

DisperseMatrix :: DisperseMatrix(DisperseMatrix &a){

    this -> numFilas = a.numFilas;
    this -> numColums = a.numColums;
    this -> listaEnlazada = a.listaEnlazada;
}  

/* Implementacion operaciones */

vector <vector <int>> DisperseMatrix :: rebuild(){

    list <pair <int, int>> :: iterator it;
    vector <vector <int>> matrizDispersa;
    vector <int> vectorNuevo;

    int recorrerFila, recorrerColumna;
    for(recorrerFila = 0; recorrerFila < numFilas; recorrerFila++){

        it = listaEnlazada[recorrerFila].begin();

        for(recorrerColumna = 0; recorrerColumna < numColums; recorrerColumna++){
            if(recorrerColumna == it->second){
                vectorNuevo.push_back(it->first);
                it++;
            } else {
                vectorNuevo.push_back(0);
            }
        }

        matrizDispersa.push_back(vectorNuevo);
        vectorNuevo.clear();
    }
    
    return matrizDispersa;
}

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

vector <pair <int, int>> DisperseMatrix :: getRowVec(int fila){

    vector <pair <int, int>> vectorFila;
    list <pair <int, int>> :: iterator it = listaEnlazada[fila].begin();

    int recorrerFila, recorrerColumna;
    for(recorrerColumna = 0; recorrerColumna < numColums; recorrerColumna++){
        if(it->second == recorrerColumna){
            pair <int, int> pareja(it->first, recorrerColumna);
            vectorFila.push_back(pareja);
            it++;
        }
    }

    return vectorFila;
}

list <pair <int, int>> DisperseMatrix :: getRowList(int fila){

    list <pair <int, int>> listaFila;
    list <pair <int, int>> :: iterator it = listaEnlazada[fila].begin();

    int recorrerFila, recorrerColumna;
    for(recorrerColumna = 0; recorrerColumna < numColums; recorrerColumna++){
        if(it->second == recorrerColumna){
            pair <int, int> pareja(it->first, recorrerColumna);
            listaFila.push_back(pareja);
            it++;
        }
    }

    return listaFila;
}

vector <pair <int, int>> DisperseMatrix :: getColVec(int columna){

    vector <pair <int, int>> vectorColumna;

    int fila, posicion;
    list <pair <int, int>> :: iterator it;

    for(fila = 0; fila < numFilas; fila++){
        bool flag = false;
        it = listaEnlazada[fila].begin();
        while(it != listaEnlazada[fila].end() && flag == false){
            if(it->second == columna){
                pair <int, int> pareja(it->first, fila);
                vectorColumna.push_back(pareja);
                flag = true;
            }  
            it++; 
        }
    }

    return vectorColumna;
}

list <pair <int, int>> DisperseMatrix :: getColList(int columna){

    list <pair <int, int>> listaColumna;

    int fila;
    list <pair <int, int>> :: iterator it;

    for(fila = 0; fila < numFilas; fila++){
        bool flag = false;
        it = listaEnlazada[fila].begin();
        while(it != listaEnlazada[fila].end() && flag == false){
            if(it->second == columna){
                pair <int, int> pareja(it->first, fila);
                listaColumna.push_back(pareja);
                flag = true;
            }  
            it++; 
        }
    }

    return listaColumna;
}

vector <pair <int, int>> DisperseMatrix :: getDisperseRowVec(int fila){

    int columna = 0;
    vector <pair <int, int>> filaDispersa;
    list <pair <int, int>> :: iterator it = listaEnlazada[fila].begin();

    int recorrerFila, recorrerColumna;
    for(recorrerColumna = 0; recorrerColumna < numColums; recorrerColumna++){
        if(it->second == recorrerColumna){
            pair <int, int> pareja(it->first, recorrerColumna);
            filaDispersa.push_back(pareja);
            it++;
        } else {
            pair <int, int> pareja(0, recorrerColumna);
            filaDispersa.push_back(pareja);
        }
    }

    return filaDispersa;
}

list <pair <int, int>> DisperseMatrix :: getDisperseRowList(int fila){

    int columna = 0;
    list <pair <int, int>> listaFilaDispersa;
    list <pair <int, int>> :: iterator it = listaEnlazada[fila].begin();

    int recorrerFila, recorrerColumna;
    for(recorrerColumna = 0; recorrerColumna < numColums; recorrerColumna++){
        if(it->second == recorrerColumna){
            pair <int, int> pareja(it->first, recorrerColumna);
            listaFilaDispersa.push_back(pareja);
            it++;
        } else {
            pair <int, int> pareja(0, recorrerColumna);
            listaFilaDispersa.push_back(pareja);
        }
    }

    return listaFilaDispersa;
}

vector <pair <int, int>> DisperseMatrix :: getDisperseColVec(int columna){

    vector <pair <int, int>> vectorColumnasDispersas;
    list <pair <int, int>> :: iterator it;

    int fila;
    for(fila = 0; fila < numFilas; fila++){
        bool flag = false;
        it = listaEnlazada[fila].begin();
        while(it != listaEnlazada[fila].end() && flag == false){
            if(it->second == columna){
                pair <int, int> pareja(it->first, fila);
                vectorColumnasDispersas.push_back(pareja);
                flag = true;
            }
            it++; 
        }

        if(flag == false){
            pair <int, int> pareja(0, fila);
            vectorColumnasDispersas.push_back(pareja);
        }
    }

    return vectorColumnasDispersas;
}

list <pair <int, int>> DisperseMatrix :: getDisperseColList(int columna){

    list <pair <int, int>> listaColumnasDispersas;
    list <pair <int, int>> :: iterator it;

    int fila;
    for(fila = 0; fila < numFilas; fila++){
        bool flag = false;
        it = listaEnlazada[fila].begin();
        while(it != listaEnlazada[fila].end() && flag == false){
            if(it->second == columna){
                pair <int, int> pareja(it->first, fila);
                listaColumnasDispersas.push_back(pareja);
                flag = true;
            }
            it++; 
        }

        if(flag == false){
            pair <int, int> pareja(0, fila);
            listaColumnasDispersas.push_back(pareja);
        }
    }

    return listaColumnasDispersas;
}

int DisperseMatrix :: getMax(){

    int valorMax = 0;
    list <pair <int, int>> :: iterator it;

    int recorrerFila;
    for(recorrerFila = 0; recorrerFila < numFilas; recorrerFila++){
        for(it = listaEnlazada[recorrerFila].begin(); it != listaEnlazada[recorrerFila].end(); it++){
            if(it->first > valorMax){
                valorMax = it->first;
            }
        }
    }

    return valorMax;
}

void DisperseMatrix :: assign(int fila, int columna, int nuevoValor){

    list <pair <int, int>> :: iterator it = listaEnlazada[fila].begin();
    bool flag = false;
    while(it != listaEnlazada[fila].end() && !flag){
        if((*it).second == columna){
            flag = true;
        }
        it++;
    }

    if(!flag && nuevoValor != 0){
        pair <int, int> pareja(nuevoValor, columna);
        listaEnlazada[fila].push_back(pareja);
    } else {
        if(nuevoValor == 0){
            it = listaEnlazada[fila].erase(it);
        } else {
            (*it).first = nuevoValor;   
        }
    }
}

void DisperseMatrix :: printMatrix(string separador){

    int recFila, contador;
    list <pair <int, int>> :: iterator it;
    for(recFila = 0; recFila < numFilas; recFila++){
        contador = 0;
        for(it = listaEnlazada[recFila].begin(); it != listaEnlazada[recFila].end(); it++){
            if(recFila != numFilas - 1 || contador < listaEnlazada[recFila].size() - 1){
                cout << it->first << " " << separador << " ";
            } else {
                cout << it->first;
            }
            contador++;
        }
    }
}

void DisperseMatrix :: add(DisperseMatrix &nuevaMatriz){

    int recorrerFila;
    list <pair <int, int>> :: iterator itMatriz, itNuevaMatriz;

    for(recorrerFila = 0; recorrerFila < numFilas; recorrerFila++){
        itNuevaMatriz = nuevaMatriz.listaEnlazada[recorrerFila].begin();
        for(itMatriz = listaEnlazada[recorrerFila].begin(); itMatriz != listaEnlazada[recorrerFila].end(); itMatriz++){
            
        }
    }

}