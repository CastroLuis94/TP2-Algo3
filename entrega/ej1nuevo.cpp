#include <iostream>
#include <ostream>
#include <vector>
#include <stdio.h>
#include "representador.h"


using namespace std;



int minimoNoProcesado(int distancias[], bool S[], int N, int k)
{
   //habia un min_index
   int min = INT_MAX;
   int indice;
   for (int n = (k+1); n < N; n++){  
       if ((S[n] == false) && (distancias[n] <= min)){        
            min = distancias[n], indice = n;
        }
    }  
   return indice;
}

//NOTA IMPORTANTE:
//Este es el Djistra usado en la solucion.  
//N = ((cantCiudades)
//origen = origen*(k+1)
void Dijkstradirijido(int origen, vector<vector <int> > &matriz, int N, int k, int distancias[]){
   
    int totalarreglo = ((N+1)*(k+1));
    bool S[totalarreglo];       
     for (int i = (k+1); i < totalarreglo; i++){
        distancias[i] = INT_MAX;            
        S[i] = false;
    }  
     distancias[origen] = 0;
     for(int count = (k+1); count < totalarreglo; count++)//decia N-1 totalarreglo-1
     {

       int u = minimoNoProcesado(distancias, S, totalarreglo, k);
         
       S[u] = true;    
      
       for (int n = (k+1)+ (u % (k+1)); n < totalarreglo; n= n + (k+1)){              
            if (!S[n] && ((matriz[u][n]) > -1)  && distancias[u]+(matriz[u][n]) < distancias[n]){
             distancias[n] = distancias[u] + (matriz[u][n]);                                    
            }
        }
        if(((u+1)%(k+1))!=0 ){  //solo ve esta guarda si nos quedan premium libres, ej k=2, no entra para nodos (1,2), (2,2), etc          
            for (int n = (k+1)+ (u % (k+1))+1; n < totalarreglo; n= n + (k+1)){  
                if (!S[n] && ((matriz[u][n]) > -1)  && distancias[u]+(matriz[u][n]) < distancias[n]){//&& (distancias[u]!= INT_MAX)
                distancias[n] = distancias[u] + (matriz[u][n]);                         
                }
            }
        }
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
        k = min(k,cantCiudades);
        //k siendo la maxima cantidad de rutas premium que puede haber 
        cout << "Ingrese las " << cantRutas << " rutas en formato: numero_ciudad1 numero_ciudad2 es_premium(0 o 1) distancia" <<endl;
        vector<vector< int > > entrada = levantarEntrada(cantRutas);//cada vector<int> es de lon = 4, y es una arista.En formato (c1, c2, p, distancia)        

        Representador rep(cantCiudades,entrada);       
        vector <vector <int> > matriz = rep.matrizConPremiums(k);//Matriz de (n*k) nodos.       
        int distancias[(cantCiudades + 1) * (k+1)]; 
        Dijkstradirijido((origen*(k+1)), matriz, cantCiudades, k, distancias);  
        int minimaDistancia = INT_MAX;

        int i = (destino*(k+1));
        while(i < (destino*(k+1)+ (k+1)) ){
            if(distancias[i] >= 0){                
            minimaDistancia = min(minimaDistancia,distancias[i]);
            }
            i++;
        }
        if (minimaDistancia == INT_MAX){
            minimaDistancia = -1;
        }       
        
        cout << minimaDistancia << endl;
        //cout << DijkstraLuis(origen,destino,cantCiudades,k,matriz) << endl;

    }  
    cout << "Fin de la ejecucion del algoritmo." << endl;
    return 0;
}



