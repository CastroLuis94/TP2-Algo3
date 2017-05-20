#!/usr/bin/python

import math
import random
import numpy as np 


#levanto parametros

def generador_grafo_fuertemente_conexo(ciudades,ejes,perctP):
	# creo un arreglo con perctP unos
	array = [0 for i in range(ejes)]
	posicionPremium = random.sample(range(0, ejes), int(ejes * (perctP / 100)))
	for i in posicionPremium:
		array[i] = 1
	#Creo una matriz de adyacencia para no repetir aristas
	Matrix = [[0 for x in range(ciudades)] for y in range(ciudades)] 
	#print n m
	print(str(ciudades) + " " + str(ejes))

	src = int(random.uniform(0,ciudades))
	dst = int(random.uniform(0,ciudades))
	while dst == src:
		dst = int(random.uniform(1,ciudades+1))

	k = int(random.uniform(0,ejes/2))
	#print segunda linea
	print (str(src)+" "+str(dst)+" "+str(k))
	#Fuerzo que sea conexo haciendo un circuito de n ejes que cubra los n nodos
	j = 1
	while(j<ciudades):
		c1 = j
		c2 = j+1
		premium = array[j-1]
		if premium == 1:
			peso = random.randrange(1,26)
		else:
			peso = random.randrange(1,101)
		Matrix[c1-1][c2-1]=1
		Matrix[c2-1][c1-1]=1
		print (str(c1) + " " +str(c2)+" "+ str(premium) + " " + str(peso))
		j+=1

	peso = int(random.uniform(0,30))
	Matrix[0][ciudades-1] = 1
	Matrix[ciudades-1][0] = 1
	print (str(ciudades) + " " + str(1) + " " + str(array[ciudades-1]) + " " + str(peso))

	# completo con ejes hasta llegar a m
	while(j < ejes):
		c1 = int(random.uniform(1,ciudades+1))
		c2 = int(random.uniform(1,ciudades+1))
		while c2 == c1:
			c2 = int(random.uniform(1,ciudades+1))
		premium = array[j]
		if premium == 1:
			peso = random.randrange(1,26)
		else:
			peso = random.randrange(1,101)
		if Matrix[c1-1][c2-1] == 0:
			Matrix[c1-1][c2-1]=1
			Matrix[c2-1][c1-1]=1
			print (str(c1) + " " +str(c2)+" "+ str(premium) + " " + str(peso))
			j+=1

if __name__ == "__main__":
	porcentaje_premium = 70
	ciudades = 2
	while(ciudades <= 100):
		for i in range(0,100):
			camino = random.randrange(ciudades,max(int(ciudades*(ciudades-1)/2 + 1) , ciudades+1))
			generador_grafo_fuertemente_conexo(ciudades,camino,porcentaje_premium)
		ciudades+=1
	print(str(-1) + " " + str(-1) )