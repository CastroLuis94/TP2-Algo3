#!/usr/bin/python

import random


class Tupla:
    def __init__(self, c1, c2, p, d=None):
        self.c1 = c1
        self.c2 = c2
        self.p = p
        if d != 0:
            if p == 0:
                self.d = random.randrange(1, 101)
            else:
                self.d = random.randrange(1, 26)
        else:
            self.d = 0

    def __repr__(self):
        print(str(self.c1) + " " + str(self.c2) + " " + str(self.p) + " " + str(self.d) + " ")

    def __str__(self):
        representacion = str(self.c1) + " " + str(self.c2) + " " + str(self.p) + " " + str(self.d)
        return representacion


def generador_grafo_random(num_ciudades, num_rutas):
    ciudades_origen = [i for i in range(0, num_ciudades)]
    ciudades_destino = [random.choice(ciudades_origen) for _ in range(0, num_rutas)]
    print(f'{num_ciudades} {num_rutas}')
    for i in range(num_ciudades):
        c1 = ciudades_origen[i]
        c2 = ciudades_destino.pop()
        print(f'{c1} {c2} {random.randint(0,100)}')
    for i in range(num_ciudades, num_rutas):
        c1 = random.choice(ciudades_origen)
        c2 = ciudades_destino.pop()
        print(f'{c1} {c2} {random.randint(0,100)}')


def generador_grafo_fuertemente_conexo(num_ciudades, num_rutas):
    ciudades_origen = [i for i in range(0, num_ciudades)]
    ciudades_destino = [random.choice(ciudades_origen) for _ in range(0, num_rutas)]
    print(f'{num_ciudades} {num_rutas}')
    for i in range(num_ciudades):
        c1 = ciudades_origen[i]
        c2 = ciudades_destino.pop()
        print(f'{c1} {c2} {random.randint(0,100)}')
    for i in range(num_ciudades, num_rutas):
        c1 = random.choice(ciudades_origen)
        c2 = ciudades_destino.pop()
        print(f'{c1} {c2} {random.randint(0,100)}')


if __name__ == "__main__":

    for i in range(3, 1000):
        generador_grafo_random(i, random.randint(i, i * (i - 1) / 2))
    print(-1, -1)
