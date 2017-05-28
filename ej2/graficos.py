import csv

import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns

d = open('ej2test1')
random = csv.reader(d, delimiter=';', lineterminator='\n')

bt = open('ej2test2')
completo = csv.reader(bt, delimiter=';', lineterminator='\n')

bt2 = open('ej2test3')
desconectadas = csv.reader(bt2, delimiter=';', lineterminator='\n')

bt2 = open('ej2test4')
fuertemente_conexa = csv.reader(bt2, delimiter=';', lineterminator='\n')

df = pd.DataFrame()

datos_random =  [ i for i in random]
datos_completo = [ i for i in completo ]
datos_desconectadas = [ i for i in desconectadas]
datos_fuertemente_conexa = [ i for i in  fuertemente_conexa]


df['cantidad de nodos'] = [int(i[0]) for i in datos_random]
df['completo'] = [float(i[2]) for i in datos_completo]
df['random'] = [float(i[2]) for i in datos_random]
df['desconectadas'] = [float(i[2]) for i in datos_desconectadas]
df['fuertemente_conexa'] = [float(i[2]) for i in datos_fuertemente_conexa]

plt.clf()
grafico = df.groupby('cantidad de nodos').mean().plot(title="Ejercicio 2")
grafico.set_ylabel("Tiempo en ms")
# grafico_backtracking_poda = df_backtracking_poda.groupby('cantidad de elementos').mean().plot(title="Implementación de Backtracking con poda")
# grafico_backtracking_poda.set_ylabel("Tiempo en ms")
# grafico_dinamico = df_dinamico.groupby('cantidad de elementos').mean().plot(title='Implementación de programacion dinamica')
# grafico_dinamico.set_ylabel("Tiempo en ms")
#
# sns.jointplot(df_dinamico_2['c*n^3'], df_dinamico['tiempo en ms dinamico'], kind="reg")
# sns.jointplot(df_backtracking['c*3^n'], df_backtracking['tiempo en ms backtracking sin poda'], kind="reg")

plt.show()