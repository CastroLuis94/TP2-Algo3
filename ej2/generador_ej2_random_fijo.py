#!/usr/bin/python
from ej2.generador_ej2_fuertemente_conexa import generador_grafo_fc

if __name__ == "__main__":
    i = 150
    for k in range(i, i * (i - 1)):
        generador_grafo_fc(i, k)
    print(-1, -1)
