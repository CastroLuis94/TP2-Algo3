#include <iostream>
#include <ostream>
#include <vector>
#include <stdio.h>
#include <limits.h>
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

int minimoNoProcesado(vector <vector<int> > pre, bool S[], int N, int contador[])
{
   //habia un min_index
   int min = INT_MAX;
   int indice;
   for (int n = 1; n < N+1; n++){
        if (S[n] == false && pre[contador[n]][n] <= min){
            min = pre[contador[n]][n], indice = n;
        }
    }
  
   return indice;
}

int minimoNoProcesadosP(int distancias[], bool S[], int N)
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



int Dijkstradirijido(int origen, int destino, vector<vector <Dato> > matriz, int N, int k){
    //int distancias[N+1];
    vector<int> distancias(N+1, INT_MAX);
    vector< vector< int > > pre( k+1, distancias);
    int contador[N+1];
    bool S[N+1];
     for (int i = 1; i < N+1; i++){
      //  distancias[i] = INT_MAX;
        S[i] = false;
        contador[i] = 0;
    }  
    
     pre[contador[origen]][origen] = 0;
     
     while(noSeteados(S, N))//decia N-1
     {
        
       int u = minimoNoProcesado(pre, S, N, contador);
       //cout << u << endl;
  
       S[u] = true;
        
       
       for (int n = 1; n < N+1; n++){  
            if ((!S[n]) && (d(matriz[u][n]) > -1)  && (pre[contador[u]][u]+d(matriz[u][n]) <= pre[contador[n]][n]) && (contador[u] <= k) ){
                if(premium(matriz[u][n]) and (contador[u] < k) and (k>0) ){
                    contador[n] = contador[u] + 1;
                }else{
                    contador[n] = contador[u];
                }
                if((contador[u] < k) or ((contador[u] == k)and (!premium(matriz[u][n])))){                            
                    pre[contador[n]][n] = pre[contador[u]][u] + d(matriz[u][n]);
                }
                if((contador[u] == k) and (premium(matriz[u][n])) and (k>0)){
                    contador[u]--;
                }
            }            
        }
    }   

return pre[contador[destino]][destino];
}

int Dijkstradirijidossinpremium(int origen, int destino, vector<vector <Dato> > matriz, int N, int k){
    int distancias[N+1];  
    int contador[N+1];
    bool S[N+1];
     for (int i = 1; i < N+1; i++){
        distancias[i] = INT_MAX;
        S[i] = false;
        contador[i] = 0;
    }  

     distancias[origen] = 0;
     
     while(noSeteados(S, N))//decia N-1
     {

       int u = minimoNoProcesadosP(distancias, S, N);      
  
       S[u] = true;
        
        
       for (int n = 1; n < N+1; n++){  
            if ((!S[n]) && (d(matriz[u][n]) > -1)  && (distancias[u]+d(matriz[u][n]) <= distancias[n]) && (contador[u] <= k) ){
                 if((contador[u] < k) or ((contador[u] == k)and (!premium(matriz[u][n])))){                            
                distancias[n] = distancias[u] + d(matriz[u][n]);
                }
                if(premium(matriz[u][n])){
                    contador[n]= contador[u] + 1;
                }else{
                    contador[n] = contador[u];
                }
            }            
        }
    }   
return distancias[destino];

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


int Dijkstradirijido(int origen, int destino, vector<vector <Dato> > &matriz, int N){
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
        Representador rep(cantCiudades,entrada);
        mostrar(rep.matrizAdyacencia());
        mostrar(rep.listaDeIncidencia());
        mostrar(rep.listaDeAdyacencia());
        vector<vector <Dato> > matriz = rep.matrizAdyacencia();
        cout << "Dio esto: " << Dijkstradirijido(origen, destino ,matriz,cantCiudades, k)<< endl;
        //cout << "Dio esto: " << Dijkstradirijido(origen, destino ,matriz,cantCiudades)<< endl;
    }
  
    cout << "Fin de la ejecucion del algoritmo." << endl;
    return 0;
}


