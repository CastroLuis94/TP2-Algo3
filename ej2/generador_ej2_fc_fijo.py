#!/usr/bin/python
from ej2.generador_ej2 import generador_grafo_random

if __name__ == "__main__":
    i = 150
    for k in range(i, i * (i - 1)):
        generador_grafo_random(i, k)
    print(-1, -1)
