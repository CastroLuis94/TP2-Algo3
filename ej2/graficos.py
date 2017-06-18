import csv

import matplotlib.pyplot as plt
import pandas as pd

ej2test1 = open('ej2test1')
random = csv.reader(ej2test1, delimiter=';', lineterminator='\n')
ej2test2 = open('ej2test2')
completo = csv.reader(ej2test2, delimiter=';', lineterminator='\n')
ej2test3 = open('ej2test3')
desconectadas = csv.reader(ej2test3, delimiter=';', lineterminator='\n')
ej2test4 = open('ej2test4')
fuertemente_conexo = csv.reader(ej2test4, delimiter=';', lineterminator='\n')

ej2test5 = open('ej2test5')
random_fijo = csv.reader(ej2test5, delimiter=';', lineterminator='\n')
ej2test6 = open('ej2test6')
fuertemente_conexo_fijo = csv.reader(ej2test6, delimiter=';', lineterminator='\n')

df = pd.DataFrame()
df_2 = pd.DataFrame()

datos_random = [i for i in random]
datos_random_fijo = [i for i in random_fijo]
datos_completo = [i for i in completo]
datos_desconectadas = [i for i in desconectadas]

datos_fuertemente_conexo = [i for i in fuertemente_conexo]
datos_fuertemente_conexo_fijo = [i for i in fuertemente_conexo_fijo]

datos_random_promedios = {}
datos_fc_promedios = {}

for data in datos_random:
    datos_random_promedios[data[0]] = datos_random_promedios.get(data[0], 0) + (float(data[2]) / 50)

for data in datos_fuertemente_conexo:
    datos_fc_promedios[data[0]] = datos_fc_promedios.get(data[0], 0) + (float(data[2]) / 50)

df['cantidad de nodos'] = [int(i[0]) for i in datos_completo]
df['completo'] = [float(i[2]) for i in datos_completo]

values_ = [i for i in datos_random_promedios.values()]
df['random'] = values_

df['desconectadas'] = [float(i[2]) for i in datos_desconectadas]
df['fuertemente conexo'] = [i for i in datos_fc_promedios.values()]

df_2['cantidad de ejes'] = [int(i[1]) for i in datos_random_fijo]
df_2['random fijo'] = [float(i[2]) for i in datos_random_fijo]
df_2['fuertemente conexo'] = [float(i[2]) for i in datos_fuertemente_conexo_fijo]

plt.clf()
grafico = df.groupby('cantidad de nodos').mean().plot(title="Ejercicio 2", logy=True)
grafico.set_ylabel("Tiempo en nanosegundos")

grafico_2 = df_2.groupby('cantidad de ejes').mean().plot(title="Ejercicio 2", logy=True)
grafico_2.set_ylabel("Tiempo en nanosegundos")

# grafico_backtracking_poda = df_backtracking_poda.groupby('cantidad de elementos').mean().plot(title="Implementación de Backtracking con poda")
# grafico_backtracking_poda.set_ylabel("Tiempo en ms")
# grafico_dinamico = df_dinamico.groupby('cantidad de elementos').mean().plot(title='Implementación de programacion dinamica')
# grafico_dinamico.set_ylabel("Tiempo en ms")
#
# sns.jointplot(df_dinamico_2['c*n^3'], df_dinamico['tiempo en ms dinamico'], kind="reg")
# sns.jointplot(df_backtracking['c*3^n'], df_backtracking['tiempo en ms backtracking sin poda'], kind="reg")

plt.show()
