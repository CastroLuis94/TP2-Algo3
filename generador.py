#!/usr/bin/python

import sys
import math
import random
import numpy as np

class Tupla:
    def __init__(self,c1,c2,p,d=None):
        self.c1 = c1
        self.c2 = c2
        self.p = p
        if d != 0:
            if p == 0:
                self.d = random.randrange(1,101)
            else:
                self.d = random.randrange(1,26)
        else:
            self.d = 0
    def __repr__(self):
        print(str(self.c1) + " " + str(self.c2) + " " + str(self.p) + " " + str(self.d) + " ")
    def __str__(self):
        representacion = str(self.c1) + " " + str(self.c2) + " " + str(self.p) + " " + str(self.d)
        return representacion




def generador_grafo_completo(num_ciudades, porcentaje_premium,porcentaje_distancia=None):
    rutas = int((num_ciudades)*(num_ciudades-1)/2)
    print (str(num_ciudades) + " " + str(rutas)) 
    #imprimo la primera linea
    c1 , c2 = random.sample(range(1,num_ciudades+1),2)
    # imprimo la segunda linea c1,c2 elegidas de forma random(es random es sin repetidos)
    cantidad_premium = random.sample(range(0,rutas),1)[0]
    print(str(c1) + " " + str(c2) + " " + str(cantidad_premium))
    res = []
    for i in range(1,num_ciudades+1):
        for k in range(1,num_ciudades+1):
            if (k > i):
                res.append(Tupla(i,k,0,None))
    posicion_de_premium = random.sample(range(0,len(res)),int(len(res)*(porcentaje_premium/100)) )
    for i in posicion_de_premium:
        c1 = (res[i]).c1
        c2 = (res[i]).c2
        res[i] = Tupla(c1,c2,1,None)
    random.shuffle(res)
    for elem in res:
        print(elem)



if __name__ == "__main__":
    porcentaje_premium = 70
    ciudades = 2
    while(ciudades <= 50):
        for i in range(0,100):
            generador_grafo_completo(ciudades,porcentaje_premium)
        ciudades+=1
    print(str(-1) + " " + str(-1) )