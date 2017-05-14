#include <iostream>
#include <ostream>
#include <vector>
#include <stdio.h>
#include <limits.h>

using namespace std;

struct Tupla{
    int distancia;
    bool caminoPremium;
    Tupla(){
        distancia = -1;
        caminoPremium = false;
    }
    Tupla(int d,bool cP){
        distancia = d;
        caminoPremium = cP;
    }
};

vector<vector< int > > levantarEntrada(int cantRutas){
    int i = 0;
    vector<vector< int > > res;
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

void mostrar(Tupla t) {
    cout << "(d:" << t.distancia << ",p:" << t.caminoPremium << ")";  
}

int d(Tupla t) {
    return t.distancia;  
}

bool premium(Tupla t) {
    return t.caminoPremium;  
}
    

void mostrar(vector<Tupla> vs){
    cout << "[";
    int i = 0;
    while(i < vs.size()){
        mostrar(vs[i]);
        i++;
        if(i < vs.size()){
            cout << ",";
        }
    }
    cout << "]" <<endl;
}

void mostrar(vector<vector<Tupla> > vs){
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

vector<Tupla> crearFila(int M){
    int i = 0;
    vector<Tupla> res;
    while(i < M){
        res.push_back(Tupla());
        i++;
    }
    return res;
}

vector<vector< Tupla > > matriz(int N, int M){
    int i = 0;
    vector<vector<Tupla> > res;
    vector<Tupla> fila = crearFila(M+1);
    while(i <= N){
        res.push_back(fila);
        i++;
    }
    return res;
}

vector<vector <Tupla> > matrizAdyacencia(int N, vector<vector< int > > vs){
    vector < vector <Tupla> > res = matriz(N,N);
    int i = 0;
    while(i < vs.size()){
        int ciudad1 = vs[i][0];
        int ciudad2 = vs[i][1];
        bool hayCaminoPremium;
        if (vs[i][2]==1){
            hayCaminoPremium = true;
        }else{
            hayCaminoPremium = false;
        }
        int distancia = vs[i][3];
        res[ciudad1][ciudad2] = Tupla(distancia,hayCaminoPremium);
        res[ciudad2][ciudad1] = Tupla(distancia,hayCaminoPremium);        
        // Nota importante, estoy asumiendo que si hay camino de A a B entonces hay camino de B a A y tiene la misma distancia,
        //capaz estoy flasheando
        i++;
    }
    for(int n = 1; n < N+1; n++){
        res[n][n] = Tupla(0, false);
    }
    return res;
}


int minimoNoProcesado(int distancias[], bool S[], int N)
{
   //habia un min_index
   int min = INT_MAX;
   int indice;
   for (int n = 1; n < N+1; n++){
        if (S[n] == false && distancias[n] <= min){
            min = distancias[n], indice = n;
        }
    }
  
   return indice;
}









int Dijkstradirijido(int origen, int destino, vector<vector <Tupla> > &matriz, int N){
    int distancias[N];
    bool S[N];
     for (int i = 0; i < N; i++){
        distancias[i] = INT_MAX;
        S[i] = false;
    }  
     distancias[origen] = 0;
     for (int nodos = 0; nodos < N; nodos++)//decia N-1
     {

       int u = minimoNoProcesado(distancias, S, N);
  
       S[u] = true;
  
     
       for (int n = 0; n < N; N++){  
            if (!S[n] && (d(matriz[u][n+1]) > -1) && (distancias[u]!= INT_MAX) && distancias[u]+d(matriz[u][n+1]) < distancias[n]){
             distancias[n] = distancias[u] + d(matriz[u][n+1]);
            }
        }
    }
return distancias[destino];

}

int main(){
    while(true){
        vector< vector<int> > res;
        cout << "ingrese la cantidad de ciudades" <<endl;
        int cantCiudades;
        cin >> cantCiudades;
        // n es la candidad de ciudades
        
        cout << "ingrese la cantidad de rutas" <<endl;
        int cantRutas;
        cin >> cantRutas;
        //m la cantidad de rutas
        if(cantCiudades == -1 and cantRutas == -1){
            break;
        }
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
        cout << "Ingrese las " << cantRutas << " rutas en formato: numero_ciudad1 numero_ciudad2 es_premium(0 o 1) distancia" <<endl;
        vector<vector< int > > entrada = levantarEntrada(cantRutas);
        /* Aclaracion importate.
        Todas las lineas implementadas para tomar la entrada pensaba ponerlo en una funcion auxiliar grande, pero como tengo que fijarme
        si me dan -1 -1 lo hice asi, una funcion en C++ tiene solo un tipo de salida, no puedo decir "te doy void si me pasan -1 -1 o
        un vector de vector si me dan otra cosa." Ahora, este algoritmo solo toma las entradas, despues de eso tendriamos que poner que 
        tipo de representacion queremos y correr el algoritmo que lo resuelve, si los profes corren nuestra implementacion con un 
        txt estoy bastante seguro que esto toma las X entradas y las resuelve X veces.
        Cosa importante, estoy asumiendo que el -1 -1 son los primeros numeros al empezar una nueva entrada y no estan en el medio de
        otra, caso contrario tendria que hacer un par de cambios pero no creo que sean tan forros(mejor commit ever).
        */
        mostrar(matrizAdyacencia(cantCiudades,entrada));
        vector<vector <Tupla> > matriz = matrizAdyacencia(cantCiudades,entrada);
        cout << "Dio esto: " << Dijkstradirijido(origen, destino ,matriz,cantCiudades)<< endl;
    }
  
    cout << "Fin de la ejecucion del algoritmo." << endl;
    return 0;
}


