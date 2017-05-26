#include <iostream>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include "aux.cpp"
using namespace std;


int main() {
     while (true) {
         vector<Eje> provicia;
         int cantCiudades;
         int cantRutas;
 //        cout << "Cantidad de Ciudades y Rutas." << endl;
         cin >> cantCiudades >> cantRutas;
         // n es la candidad de ciudades
         if(cantCiudades == -1 and cantRutas == -1){
             break;
         }
         for (int i = 0; i < cantRutas; ++i) {
 //            cout << "Ingrese una ruta valida." << endl;
             int c1;
             int c2;
             int p;
             cin >> c1 >> c2 >> p;
             Eje v = {c1, c2, p};
             provicia.push_back(v);
         }
         int res = maximaReduccion(provicia, cantCiudades, cantRutas);
         cout << res << endl;
     }
 //    cout << "Fin de la ejecucion del algoritmo." << endl;
     return 0;
 }
