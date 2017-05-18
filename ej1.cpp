#include <iostream>
#include <ostream>
#include <vector>
#include <stdio.h>
#include "representador.h"



using namespace std;

bool noSeteados(bool S[], int N){
    bool b= true;
    for(int i =1; i<N+1; i++){
        if(S[i] == false){
            return true;
        }
    }
    return false;

}



int minimoNoProcesado(int distancias[], bool S[], int N)
{
   //habia un min_index
   int min = INT_MAX;
   int indice;
   for (int n = 1; n < N+1; n++){
        if (S[n] == false && distancias[n] < min){
            min = distancias[n], indice = n;
        }
    }
  
   return indice;
}


void Dijkstradirijido(int origen, int destino, vector<vector <Dato> > &matriz, int N, int distancias[], int antecesor[]){
    //int distancias[N+1];
    bool S[N+1];
    // antecesor[];   
     for (int i = 1; i < N+1; i++){
        distancias[i] = INT_MAX;
        antecesor[i] = i;     
        S[i] = false;
    }  
     distancias[origen] = 0;
     while(noSeteados(S, N))//decia N-1
     {

       int u = minimoNoProcesado(distancias, S, N);
  
       S[u] = true;
  
     
       for (int n = 1; n < N+1; n++){  
            if (!S[n] && (d(matriz[u][n]) > -1)  && distancias[u]+d(matriz[u][n]) < distancias[n]){//&& (distancias[u]!= INT_MAX)
             distancias[n] = distancias[u] + d(matriz[u][n]);
             antecesor[n] = u;             
            }
        }
    }
}

void DijkstradirijidoSol(int origen, int destino, vector<vector <Dato> > &matriz, int N, int distancias[], int antecesor[], int cantPremium[]){
    //int distancias[N+1];
    bool S[N+1];
    // antecesor[];   
     for (int i = 1; i < N+1; i++){
        distancias[i] = INT_MAX;
        antecesor[i] = i;     
        S[i] = false;
        cantPremium[i] = 0;
    }  
     distancias[origen] = 0;
     while(noSeteados(S, N))//decia N-1
     {

       int u = minimoNoProcesado(distancias, S, N);
  
       S[u] = true;
  
     
       for (int n = 1; n < N+1; n++){  
            if (!S[n] && (d(matriz[u][n]) > -1)  && distancias[u]+d(matriz[u][n]) < distancias[n]){//&& (distancias[u]!= INT_MAX)
             distancias[n] = distancias[u] + d(matriz[u][n]);
             antecesor[n] = u;
             if(premium(matriz[u][n])){
             	cantPremium[n] = cantPremium[u]+1;
             }else{
             	cantPremium[n] = cantPremium[u];
             }             
            }
        }
    }
}




int DijkstraLuis(int origen,int destino,int cantCiudades,int k,vector<vector<Dato> > matrizEntrada){
    vector<vector<bool> > yaPase = matrizBooleana(cantCiudades,k);
    //matriz ciudad por cantidad de caminos premium que podemos usar
    vector <vector< int > > caminosRecorridos = matrizEnteros(cantCiudades,k);
    //matriz ciudad por cantidad de caminosP, distancia.
    list<tuple<int,int,int,int> > listaLindantes;
    //Dada una ciudad voy a queres sus adyacente, de donde vino, cantidad de caminos premium usados para llegar hasta ahi y la distancia.
    listaLindantes.push_front(make_tuple(origen,0,0,0));
    while(not listaLindantes.empty()){
        tuple<int,int,int,int> t = listaLindantes.front();
        listaLindantes.pop_front();
        int ciudadADondeLlegue = get<0>(t);
        int cantidadCP = get<2>(t);
        int distancia = get<3>(t);
        if (esElMejorCamino(caminosRecorridos,ciudadADondeLlegue,cantidadCP,distancia)){
            agregarLindantes(matrizEntrada,listaLindantes,t,k);
            //agregar lindante usa la segunda coordenada para saber de donde vino, asi no las vuelve a contar.
            caminosRecorridos.at(ciudadADondeLlegue).at(cantidadCP) = distancia;
            yaPase.at(ciudadADondeLlegue).at(cantidadCP) = true;
        }
    }
   
    int minimaDistancia = INT_MAX;
    int i = 0;
    while(i < caminosRecorridos[destino].size()){
        minimaDistancia = min(minimaDistancia,caminosRecorridos[destino][i]);
        i++;
    }
    if (minimaDistancia == INT_MAX){
        return -1;
    }else{
        return minimaDistancia;
    }
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
        Representador rep(cantCiudades,entrada);
        //mostrar(rep.matrizAdyacencia());
        //mostrar(rep.listaDeIncidencia());
        //mostrar(rep.listaDeAdyacencia());
        vector<vector <Dato> > matriz = rep.matrizAdyacencia();
        int distancias[cantCiudades + 1];
        int antecesor[cantCiudades + 1];
        int cantPremium[cantCiudades + 1];
        //bool rutasprem[cantCiudades + 1];
        cout << DijkstraLuis(origen,destino,cantCiudades,k,matriz) << endl;
       
        //cout << "Dio esto: " << antecesor[1] <<  antecesor[2] << antecesor[3] << antecesor[4] << endl;
        //cout << "Dio esto: " << rutasprem[1] <<  rutasprem[2] << rutasprem[3] << rutasprem[4] << endl;
        //cout << "Dio esto: " << Dijkstradirijido(origen, destino ,matriz,cantCiudades)<< endl;
    }
  
    cout << "Fin de la ejecucion del algoritmo." << endl;
    return 0;
}



/*
int main(){
    vector <int> imprimir;
    while(true){
        int cantCiudades;
        cin >> cantCiudades;
        // n es la candidad de ciudades
        
        int cantRutas;
        cin >> cantRutas;
        //m la cantidad de rutas
        if(cantCiudades == -1 and cantRutas == -1){
            break;
        }
        int origen;
        cin >> origen;
        
        
        int destino;
        cin >> destino;
        

        int k;
        cin >> k;
        //k siendo la maxima cantidad de rutas premium que puede haber 
        vector<vector< int > > entrada = levantarEntrada(cantRutas);
      
        Representador rep(cantCiudades,entrada);
        //mostrar(rep.matrizAdyacencia());
        //mostrar(rep.listaDeIncidencia());
        //mostrar(rep.listaDeAdyacencia());
        vector<vector <Dato> > matriz = rep.matrizAdyacencia();
        int distancias[cantCiudades + 1];
        int antecesor[cantCiudades + 1];
        int cantPremium[cantCiudades + 1];
        //bool rutasprem[cantCiudades + 1];
        int aAgregar = DijkstraLuis(origen,destino,cantCiudades,k,matriz);
        imprimir.push_back(aAgregar);
       
        //cout << "Dio esto: " << antecesor[1] <<  antecesor[2] << antecesor[3] << antecesor[4] << endl;
        //cout << "Dio esto: " << rutasprem[1] <<  rutasprem[2] << rutasprem[3] << rutasprem[4] << endl;
        //cout << "Dio esto: " << Dijkstradirijido(origen, destino ,matriz,cantCiudades)<< endl;
    }
    cout << "resultados = ";
    mostrar(imprimir);
    return 0;
}
*/