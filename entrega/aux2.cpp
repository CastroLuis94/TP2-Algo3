#include "aux.h"

#include <vector>
#include <limits.h>

// Para bellman ford un grafo va ser un vector de vertices
struct Eje {
    int origen, destino, peso;
};

void relajar(std::vector<int> &distancias, Eje &grafo) {
    if (distancias[grafo.origen - 1] + grafo.peso < distancias[grafo.destino - 1]) {
        distancias[grafo.destino - 1] = distancias[grafo.origen - 1] + grafo.peso;
    }
}

// A este bellman ford lo tiene que usar una funcion que a partir del grafo de entrada
// otro grafo que tenga un vertice que tenga grado de salida n (ese tiene que va a ser el origen)
// y otro grado de entrada n . Asi se asegura que se pueden encontrar ciclos negativos del grafo .
bool bellmanFord(int origen, std::vector<Eje> &grafo, int n, int m) {
    int i, j;
    std::vector<int> distancias;
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
        if (distancias[grafo[j].origen - 1] + grafo[j].peso < distancias[grafo[j].destino - 1]) return false;
    }

    return true;
}

bool bellmanFordMod(std::vector<Eje> &grafo, int n, int m) {

    //    Agrego un vertice s t que se conectan a todos los nodos
    for (int i = 0; i < n; ++i) {
        Eje s = {n + 1, i, 1};
        Eje t = {i, n + 2, 1};
        grafo.push_back(s);
        grafo.push_back(t);
    }

    return bellmanFord(n, grafo, n + 2, m + 2*n);
}

int minimo(std::vector<Eje> &vector, int m) {
    int min = INT_MAX;
    for (int i = 0; i < m; ++i) {
        if (vector[i].peso < min) { min = vector[i].peso; }
    }
    return min;
}

int maximo(std::vector<Eje> &vector, int m) {
    int max = -1;
    for (int i = 0; i < m; ++i) {
        if (vector[i].peso > max) { max = vector[i].peso; }
    }
    return max;
}

int maximaReduccion(std::vector<Eje> &grafo, int n, int m) {
    int sup = maximo(grafo, m) + 1;
    int inf = minimo(grafo, m);
    int c = sup;

    while (inf + 1 < sup) {
        c = ((sup - inf) / 2) + inf;
        std::vector<Eje> grafo_auxiliar;

        for (int j = 0; j < m; ++j) {
            Eje v = {grafo[j].origen, grafo[j].destino, grafo[j].peso - c};
            grafo_auxiliar.push_back(v);
        }
        
        if (bellmanFordMod(grafo_auxiliar, n, m)) {
            inf = c;
        } else {
            sup = c;
        }

    }
    return inf;

}