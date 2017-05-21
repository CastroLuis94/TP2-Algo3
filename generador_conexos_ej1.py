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
    

def armarArbol(arbol):
    i = 1
    res = []
    while i< len(arbol):
        res.append(Tupla(arbol[0],arbol[i],0,None))
        i += 1
    return res

def nodos_sueltos(arbol):
    if len(arbol) == 1:
        return arbol
    else:
        res = []
        for i in range(0,len(arbol)):
            for k in range(i+1, len(arbol) + 1):
                res.append(Tupla(i,k,0,None))
        return res

def conectar(arboles,nodos_sueltos):
    res = []
    for arbol in arboles:
        for elem in arbol:
            res.append(elem)
    i = 0
    while i < len(arboles)-1:
        res.append(Tupla(arboles[i][0].c1,arboles[i+1][0].c1,0,None))
        i+=1
    if len(arboles) >= 1:
        for elem in nodos_sueltos:
            res.append(Tupla(arboles[i][0].c1,elem,0,None))
    else:
        while i < len(nodos_sueltos)-1:
            res.append(Tupla(nodos_sueltos[i],nodos_sueltos[i+1],0,None))
            i+=1
    return res

def tamanio_arboles(numero_ciudades,cant_arboles):
    res = []
    while(numero_ciudades >= cant_arboles):
        res.append(int(cant_arboles))
        numero_ciudades -= cant_arboles
    if numero_ciudades != 0:
        res.append(numero_ciudades)
    return res

def generador_grafo_conexo(numero_ciudades,porcentaje_premium):
    numero_aristas = numero_ciudades-1
    aristas = []
    cant_arboles = random.randrange(2,numero_ciudades + 1)
    arboles = []
    ciudades = range(1,numero_ciudades + 1)
    arbol_trivial = []
    tamanio_de_arboles = tamanio_arboles(numero_ciudades,cant_arboles)
    print("{0} {1}".format(numero_ciudades, numero_aristas))
    c1, c2 = random.sample(range(1, numero_ciudades + 1), 2)
    cantidad_premium_permitidos = random.sample(range(0, numero_aristas), 1)[0]
    print("{0} {1} {2}".format(c1, c2, cantidad_premium_permitidos)) 
    for i in range(len(tamanio_de_arboles)):
        arbol = random.sample(ciudades, tamanio_de_arboles[0])
        tamanio_de_arboles = tamanio_de_arboles[1:]
        ciudades = list(set(ciudades) - set(arbol))
        if len(arbol) > 1:
            arboles.append(armarArbol(arbol))
        else:
            arbol_trivial.append(arbol[0])
    res = conectar(arboles,arbol_trivial)
    cantidad_premium = random.sample(range(0,len(res)), int(len(res)*porcentaje_premium/100))
    for premium in cantidad_premium:
        res[premium] = Tupla(res[premium].c1,res[premium].c2,1,None)
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
