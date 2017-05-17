#include <iostream>
#include <ostream>
#include <vector>
#include <stdio.h>
#include "representador.h"

using namespace std;

vector<int> *inicializarBellman(int n) {

}

// Para bellman ford un grafo va ser un vector de vertices
struct Eje {
    int origen, destino, peso;
};

void relajar(vector<int> &distancias, Eje grafo) {
    if (distancias[grafo.origen] + grafo.peso < distancias[grafo.destino]) {
        distancias[grafo.destino] = distancias[grafo.origen] + grafo.peso;
    }
}

// bellman no se lleva bien con matrices de adyacencia
// me parece hay que usar otra representacion que me devuelva las aristas
// A este bellman ford lo tiene que usar una funcion que a partir del grafo de entrada
// otro grafo que tenga un vertice que tenga grado de salida n (ese tiene que va a ser el origen)
// y otro grado de entrada n . Asi se asegura que se pueden encontrar ciclos negativos del grafo .
bool bellmanFord(int origen, vector<Eje> &grafo, int n, int m) {
    int i, j;
    vector<int> distancias;
    for (i = 0; i < n; ++i) {
        distancias.push_back(INT_MAX); // Esto no tengo idea de si hacerlo asi , una distancia invalida
    }
    distancias[origen] = 0;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < m; ++j) {
            relajar(distancias, grafo[j]);
        }
    }
    for (j = 0; j < m; ++j) {
        if (distancias[grafo[j].origen] + grafo[j].peso < distancias[grafo[j].destino]) return false;
    }

    return true;
}