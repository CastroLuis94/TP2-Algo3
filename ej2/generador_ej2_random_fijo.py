#!/usr/bin/python
from generador_ej2_fuertemente_conexa import generador_grafo_fc

if __name__ == "__main__":
    cant_vertices = 50
    for k in range(cant_vertices, cant_vertices * (cant_vertices - 1)):
        for i in range(50):
            generador_grafo_fc(cant_vertices, k)
    print(-1, -1)
