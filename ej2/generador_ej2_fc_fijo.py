#!/usr/bin/python
from generador_ej2 import generador_grafo_random

if __name__ == "__main__":
    cant_vertices = 50
    for k in range(cant_vertices, cant_vertices * (cant_vertices - 1)):
        generador_grafo_random(cant_vertices, k)
    print(-1, -1)
