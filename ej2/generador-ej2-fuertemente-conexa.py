#!/usr/bin/python

import random


def generador_grafo_fc(n, m):
    ciudades_origen = [i + 1 for i in range(0, n)]
    ciudades_destino = [[] for _ in range(0, n)]
    # Creo los destinos posibles para cada
    for i in ciudades_origen:
        for j in ciudades_origen:
            if j != i:
                ciudades_destino[i - 1].append(j)

    ciudades = [i for i in range(1, n + 1)]

    print(f'{n} {m}')

    random.shuffle(ciudades)
    anterior = ciudades[0]
    for i in range(1, n):
        c1 = anterior
        c2 = ciudades[i]
        ciudades_destino[c1 - 1].remove(c2)
        anterior = c2
        print(f'{c1} {c2} {random.randint(0,50)}')

    print(f'{anterior} {ciudades[0]} {random.randint(0,50)}')
    for i in range(n, m):
        c1 = random.choice(ciudades_origen)
        c2 = ciudades_destino[c1 - 1].pop()
        if len(ciudades_destino[c1 - 1]) == 0:
            ciudades_origen.remove(c1)
        print(f'{c1} {c2} {random.randint(0,50)}')


if __name__ == "__main__":
    for i in range(2, 500+1):
        generador_grafo_fc(i, random.randint(i, i * (i - 1)))
    print(-1, -1)
