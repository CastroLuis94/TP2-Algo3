import random

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
        representacion = str(self.c1) + " " + str(self.c2) + " " + str(self.p) + " " + str(self.d)
        return representacion
    def __str__(self):
        representacion = str(self.c1) + " " + str(self.c2) + " " + str(self.p) + " " + str(self.d)
        return representacion
    




def generador_grafo_conexo(numero_ciudades,porcentaje_premium):
    numero_aristas = numero_ciudades-1
    ciudades = range(1,numero_ciudades + 1)
    caminos = []
    c1 , c2 = random.sample(ciudades, 2)
    caminos.append(Tupla(c1,c2,0,None))
    ciudades = list(set(ciudades) - set([c1,c2]))
    while len(ciudades) > 0:
        c = random.sample(ciudades, 1)[0]
        ciudades.remove(c)
        ciudad_a_conectarse = random.sample([0,1], 1)
        camino_elegido = random.sample(range(len(caminos)), 1)[0]
        if ciudad_a_conectarse == 0:
            caminos.append(Tupla((caminos[camino_elegido]).c1,c,0,None))
        else:
            caminos.append(Tupla((caminos[camino_elegido]).c2,c,0,None))
    cantidad_premium = random.sample(range(0,len(caminos)), int(len(caminos)*porcentaje_premium/100))
    res = caminos
    for premium in cantidad_premium:
        res[premium] = Tupla(caminos[premium].c1,caminos[premium].c2,1,None)
    print("{0} {1}".format(numero_ciudades, len(caminos)))
    c1, c2 = random.sample(range(1, numero_ciudades + 1), 2)
    if len(res) > 0:
        cantidad_premium_permitidos = random.sample(range(0, len(res)), 1)[0]
        print("{0} {1} {2}".format(c1, c2, cantidad_premium_permitidos)) 
    else:
        print("{0} {1} {2}".format(c1, c2, 0)) 
    for elem in res:
        print(elem)
   

if __name__ == "__main__":
    porcentaje_premium = 70
    ciudades = 2
    while(ciudades <= 100):
        for i in range(0,100):
            generador_grafo_conexo(ciudades,porcentaje_premium)
        ciudades+=1
    print(str(-1) + " " + str(-1) )
