#!/usr/bin/python

import sys
import math
import random
import numpy as np

class Tupla:
    def __init__(self,c1,c2,e,p):
        self.c1 = c1
        self.c2 = c2
        self.e = e
        self.p = p
    def __repr__(self):
        representacion = str(self.c1) + " " + str(self.c2) + " " + str(self.e) + " " + str(self.p)
        return representacion
    def __str__(self):
        representacion = str(self.c1) + " " + str(self.c2) + " " + str(self.e) + " " + str(self.p)
        return representacion




def generador_grafo_completo(num_ciudades):
    caminos = int((num_ciudades) * (num_ciudades - 1) / 2)
    print("{0}".format(num_ciudades))
    res = []
    for i in range(1, num_ciudades + 1):
        for k in range(1 , num_ciudades + 1):
            if k > i:
                costo = random.randrange(1,101)
                res.append(Tupla(i,k,1,costo))
    random.shuffle(res)
    for elem in res:
        print(elem)



if __name__ == "__main__":
    ciudades = 2
    while(ciudades <= 100):
        for i in range(0,100):
            generador_grafo_completo(ciudades)
        ciudades+=1
    print(str(-1))
