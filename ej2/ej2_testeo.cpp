#include "aux.cpp"

#include <iostream>
#include <time.h>
#include <chrono>
#include <fstream>
#include <sstream>
#include <stdio.h>

#define ya chrono::high_resolution_clock::now

using namespace std;

int main() {
    char buffer[300]={0};   // lo usaremos para guardar el nombre del fichero


    sprintf(buffer, "ejercicio2_test1.csv"); // Ahora tenemos en buffer = "holaXX.txt"

    ofstream salida;
    salida.open(buffer, ios::out);
    vector<int> archivo;

    if(salida.fail()){
        cerr << "No se abrio bien el archivo" << endl;
        return 1;
    }
    //salida << "Ciudades, Rutas, tiempo1\n";

    while (true) {
        vector<Eje> provicia;
        int cantCiudades;
        int cantRutas;
//        cout << "Cantidad de Ciudades y Rutas." << endl;
        cin >> cantCiudades >> cantRutas;
        // n es la candidad de ciudades
        if(cantCiudades == -1 and cantRutas == -1){
            salida.close();
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
        auto start = ya();
        int res = maximaReduccion(provicia, cantCiudades, cantRutas);
        auto end = ya();
        archivo.push_back(chrono::duration_cast<chrono::nanoseconds>(end-start).count());
        salida << cantCiudades << ";" << cantRutas << ";" <<chrono::duration_cast<chrono::nanoseconds>(end-start).count() << endl;
        cout << res << endl;
    }
    salida << "res = ";
    salida << "[";
    int i = 0;
    while(i < archivo.size()){
        salida << archivo[i];
        i++;
        if(i < archivo.size()){
            salida << ",";
        }
    }
    salida << "]" <<endl;
    salida.close();
//    cout << "Fin de la ejecucion del algoritmo." << endl;
    return 0;
}
