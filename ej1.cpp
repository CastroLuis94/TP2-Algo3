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
    //int distancias[N+1];
    int totalarreglo = ((N+1)*(k+1));
    bool S[totalarreglo];
    // antecesor[];   
     for (int i = (k+1); i < totalarreglo; i++){
        distancias[i] = INT_MAX;            
        S[i] = false;
    }  
     distancias[origen] = 0;
     for(int count = (k+1); count < totalarreglo; count++)//decia N-1 totalarreglo-1
     {

       int u = minimoNoProcesado(distancias, S, totalarreglo, k);
       //cout << "DEJEN LOS CORES1" << u <<  endl;    
       S[u] = true;    
     
       //cout << "DEJEN LOS CORES" << endl;  
       for (int n = (k+1); n < totalarreglo; n++){  
            if (!S[n] && ((matriz[u][n]) > -1)  && distancias[u]+(matriz[u][n]) < distancias[n]){//&& (distancias[u]!= INT_MAX)
             distancias[n] = distancias[u] + (matriz[u][n]);                         
            }
        }
    }
}

/*//Djistra basico
void Dijkstradirijido(int origen, int destino, vector<vector <int> > &matriz, int N, int distancias[]){
    //int distancias[N+1];
    bool S[N+1];
    // antecesor[];   
     for (int i = 1; i < N+1; i++){
        distancias[i] = INT_MAX;            
        S[i] = false;
    }  
     distancias[origen] = 0;
     for(int count = 1; count < N+1; count++)
     {

       int u = minimoNoProcesado(distancias, S, N);
  
       S[u] = true;
  
     
       for (int n = 1; n < N+1; n++){  
            if (!S[n] && (d(matriz[u][n]) > -1)  && distancias[u]+d(matriz[u][n]) < distancias[n]){//&& (distancias[u]!= INT_MAX)
             distancias[n] = distancias[u] + d(matriz[u][n]);                         
            }
        }
    }
}

*/


/*
void DijkstraLuis(int origen,int destino,int cantCiudades,int k,vector<vector<Dato> > matrizEntrada){
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
}*/

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
       // mostrar(matriz);
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
