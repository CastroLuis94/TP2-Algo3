#include <iostream>
#include <ostream>
#include <vector>

using namespace std;


vector<vector< int > > levantarEntrada(){
    vector< vector<int> > res;
    cout << "ingrese la cantidad de ciudades" <<endl;
    int cantCiudades;
    cin >> cantCiudades;
    // n es la candidad de ciudades
    
    cout << "ingrese la cantidad de rutas" <<endl;
    int cantRutas;
    cin >> cantRutas;
    //m la cantidad de rutas
    cout << "¿Cual es la ciudad de origen?" <<endl;
    int origen;
    cin >> origen;
    
    cout << "¿Cual es la ciudad de destino?" <<endl;
    int destino;
    cin >> destino;
    
    cout << "¿Cual es la cantidad de rutas premium?" <<endl;
    int k;
    cin >> k;
    //k siendo la maxima cantidad de rutas premium que puede haber 

    cout << "Ingrese las m rutas en formato: numero_ciudad1 numero_ciudad2 es_premium(0 o 1) distancia" <<endl;
    int i = 0;
    while(i < cantRutas){
        vector<int> camino;
        int ciudad1;
        cin >> ciudad1;
        int ciudad2;
        cin >> ciudad2;
        int premium;
        cin >> premium;
        int distancia;
        cin >> distancia;
        camino.push_back(ciudad1);
        camino.push_back(ciudad2);
        camino.push_back(premium);
        camino.push_back(distancia);
        res.push_back(camino);
        i++;
    }
    return res;
}

void mostrar(vector<int> vs){
    cout << "[";
    int i = 0;
    while(i < vs.size()){
        cout << vs[i];
        i++;
        if(i < vs.size()){
            cout << ",";
        }
    }
    cout << "]" <<endl;
}

void mostrar(vector<vector<int> > vs){
    cout << "[";
    int i = 0;
    while(i < vs.size()){
        mostrar(vs[i]);
        i++;
        if(i < vs.size()){
            cout << ",";
        }
    }
    cout << "]"<<endl;
}
int main(){
    mostrar(levantarEntrada());
    return 0;
}