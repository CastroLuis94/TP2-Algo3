#!/usr/bin/python

import sys
import math
import random
import numpy as np

class Tupla:
    def __init__(self,c1,c2,e,p = None):
        self.c1 = c1
        self.c2 = c2
        self.e = e
        if p == None:
            self.p = random.randrange(1,101)
        else:
            self.p = p
    def __repr__(self):
        representacion = str(self.c1) + " " + str(self.c2) + " " + str(self.e) + " " + str(self.p)
        return representacion
    def __str__(self):
        representacion = str(self.c1) + " " + str(self.c2) + " " + str(self.e) + " " + str(self.p)
        return representacion
    def __eq__(self,otro):
        return (self.c1 == otro.c1 and self.c2 == otro.c2) or (self.c1 == otro.c2 and self.c2 == otro.c1)


def generador_grafo_conexo(numero_ciudades):
    caminos = int((numero_ciudades) * (numero_ciudades - 1) / 2)
    print("{0}".format(numero_ciudades))
    res = []
    for i in range(1, numero_ciudades + 1):
        for k in range(1 , numero_ciudades + 1):
            if k > i:
                costo = random.randrange(1,101)
                res.append(Tupla(i,k,0,costo))
    ciudades = range(1,numero_ciudades + 1)
    caminos = []
    c1 , c2 = random.sample(ciudades, 2)
    caminos.append(Tupla(c1,c2,1,None))
    ciudades = list(set(ciudades) - set([c1,c2]))
    while len(ciudades) > 0:
        c = random.sample(ciudades, 1)[0]
        ciudades.remove(c)
        ciudad_a_conectarse = random.sample([0,1], 1)
        camino_elegido = random.sample(range(len(caminos)), 1)[0]
        if ciudad_a_conectarse == 0:
            caminos.append(Tupla((caminos[camino_elegido]).c1,c,1,None))
        else:
            caminos.append(Tupla((caminos[camino_elegido]).c2,c,1,None))
    cantidad_a_borrar = random.sample(range(1,len(caminos) + 1), 1)[0]
    indice_elementos_a_borrar = random.sample(range(0,len(caminos)), random.randrange(1,len(caminos) + 1))
    indice_elementos_a_borrar.sort()
    indice_elementos_a_borrar.reverse()
    for elem in indice_elementos_a_borrar:
        caminos.pop(elem)
    for aBorrar in caminos:
        res.remove(aBorrar)
    for aAgregar in caminos:
        res.append(aAgregar)
    random.shuffle(res)
    for elem in res:
        print(elem)



if __name__ == "__main__":
    ciudades = 2
    while(ciudades <= 100):
        for i in range(0,100):
            generador_grafo_conexo(ciudades)
        ciudades+=1
    print(str(-1))
