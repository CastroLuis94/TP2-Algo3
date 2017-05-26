#!/usr/bin/python

import random


def generador_grafo_random(num_ciudades, num_rutas):
    ciudades_origen = [i + 1 for i in range(0, num_ciudades)]
    ciudades_destino = [[] for _ in range(0, num_ciudades)]
    # Creo los destinos posibles para cada
    for i in ciudades_origen:
        for j in ciudades_origen:
            if j != i:
                ciudades_destino[i - 1].append(j)

    print(f'{num_ciudades} {num_rutas}')
    for i in range(num_ciudades):
        random.shuffle(ciudades_destino[i])
        c1 = ciudades_origen[i]
        c2 = ciudades_destino[i].pop()

        print(f'{c1} {c2} {random.randint(0,50)}')
    for i in range(num_ciudades, num_rutas):
        c1 = random.choice(ciudades_origen)
        c2 = ciudades_destino[c1 - 1].pop()
        if len(ciudades_destino[c1 - 1]) == 0:
            ciudades_origen.remove(c1)
        print(f'{c1} {c2} {random.randint(0,50)}')


# def generador_grafo_fuertemente_conexo(num_ciudades, num_rutas):
#     ciudades_origen = [i for i in range(0, num_ciudades)]
#     ciudades_destino = [random.choice(ciudades_origen) for _ in range(0, num_rutas)]
#     print(f'{num_ciudades} {num_rutas}')
#     for i in range(num_ciudades):
#         c1 = ciudades_origen[i]
#         c2 = ciudades_destino.pop()
#         print(f'{c1} {c2} {random.randint(0,100)}')
#     for i in range(num_ciudades, num_rutas):
#         c1 = random.choice(ciudades_origen)
#         c2 = ciudades_destino.pop()
#         print(f'{c1} {c2} {random.randint(0,100)}')


if __name__ == "__main__":
    for i in range(2, 500 + 1):
        generador_grafo_random(i, random.randint(i, i*(i-1)))
        # generador_grafo_random(i, i * (i - 1))
    print(-1, -1)
