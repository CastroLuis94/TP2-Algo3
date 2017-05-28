#!/usr/bin/python

import random


def generador_grafo_desconectado(num_ciudades):
    ciudades_origen = [i + 1 for i in range(0, num_ciudades)]
    ciudades_destino = [i + 1 for i in range(0, num_ciudades)]
    # Creo los destinos posibles para cada
    random.shuffle(ciudades_origen)
    print(f'{num_ciudades} {num_ciudades}')
    for i in range(0, num_ciudades, 2):
        c1 = ciudades_origen.pop()
        if len(ciudades_origen) > 0:
            c2 = ciudades_origen.pop()
            print(f'{c1} {c2} {random.randint(0,100)}')
            print(f'{c2} {c1} {random.randint(0,100)}')

        else:
            ciudades_destino.remove(c1)
            c2 = random.choice(ciudades_destino)
            print(f'{c1} {c2} {random.randint(0,100)}')


if __name__ == "__main__":
    for i in range(2, 500+1):
        # generador_grafo_random(i, random.randint(i, i*(i-1)))
        generador_grafo_desconectado(i)
    print(-1, -1)
