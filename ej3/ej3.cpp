#include <iostream>
#include <ostream>
#include <vector>
#include <stdio.h>
#include "representador.h"
#include "DSU.h"



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


//me guardo la lista de las aristas en formato(c, c1, c2, e)//las ciudades van de 0 a N-1
list< tuple<int, int, int, int> >  Kruskal(list<tuple<int, int, int, int> >& aristas, int &peso, int &rutas, int n){    
    DisjointSet DisSet(n);
    list< tuple<int, int, int, int> > res;
    aristas.sort();//se supone que esto es O(NlogN)
    for(list< tuple<int, int, int, int> >::iterator it = aristas.begin(); it != aristas.end(); it++){//Recorro la lista de manera ordenada.  
        if (DisSet.find(get<1>(*it)) != DisSet.find(get<2>(*it))){            
            res.push_back(*it);
            rutas++;
            cout<< "falla"<< get<3>(*it)<< " " << get<0>(*it) << endl;
            if(!(get<3>(*it))){
                peso = peso + get<0>(*it);                
            }            
            DisSet.Nunion(get<1>(*it), get<2>(*it));            
        }else{
            if((get<3>(*it))){
                peso = peso - get<0>(*it);//si existe los costos son negativos.(por lo que para que sume bien debo darlo vuelta)
            }
        }
    }   
    return res;
}


list<tuple<int, int> > acomodarAristas(list<tuple< int, int, int, int> > &lista ){
    list<tuple<int, int> > res;
    tuple<int, int> posicion;
    for(list< tuple<int, int, int, int> >::iterator it = lista.begin(); it != lista.end(); it++){
        get<0>(posicion) = get<1>(*it); 
        get<1>(posicion) = get<2>(*it);
        res.push_back(posicion);
    }
    return res;
}




int main(){
    while(true){
        vector< vector<int> > res;
        cout << "ingrese la cantidad de ciudades" <<endl;
        int cantCiudades;
        cin >> cantCiudades;
        // n es la candidad de ciudades
        if(cantCiudades == -1){
            break;
        }
        int cantRutas = (cantCiudades*(cantCiudades-1))/2;
        

        cout << "Ingrese las " << cantRutas << " rutas en formato: numero_ciudad1 numero_ciudad2 es_premium(0 o 1) distancia" <<endl;
       // vector<vector< int > > entrada = levantarEntrada(cantRutas);
        list<tuple<int, int, int, int > > aristas = listaAristas(cantRutas);        
        //me guardo la lista de las aristas en formato(c, c1, c2, e)
       

        /* Aclaracion importate.
        Todas las lineas implementadas para tomar la entrada pensaba ponerlo en una funcion auxiliar grande, pero como tengo que fijarme
        si me dan -1 -1 lo hice asi, una funcion en C++ tiene solo un tipo de salida, no puedo decir "te doy void si me pasan -1 -1 o
        un vector de vector si me dan otra cosa." Ahora, este algoritmo solo toma las entradas, despues de eso tendriamos que poner que 
        tipo de representacion queremos y correr el algoritmo que lo resuelve, si los profes corren nuestra implementacion con un 
        txt estoy bastante seguro que esto toma las X entradas y las resuelve X veces.
        Cosa importante, estoy asumiendo que el -1 -1 son los primeros numeros al empezar una nueva entrada y no estan en el medio de
        otra, caso contrario tendria que hacer un par de cambios pero no creo que sean tan forros(mejor commit ever).
        */
       // Representador rep(cantCiudades,entrada);
        //mostrar(rep.matrizAdyacencia());
        //mostrar(rep.listaDeIncidencia());
        //mostrar(rep.listaDeAdyacencia());
        //vector<vector <Dato> > matriz = rep.matrizAdyacencia();
        int peso = 0;
        int rutas = 0;       
        list<tuple<int, int, int, int> > resultado = Kruskal(aristas,  peso,  rutas, cantCiudades);
        cout << "peso"<<peso << endl;
        list<tuple<int, int> > aristassolucion = acomodarAristas(resultado);

        cout<< peso <<" "<< rutas << " ,";
        for(list<tuple<int, int> >::iterator iter = aristassolucion.begin(); 
        iter != aristassolucion.end(); iter++){
        cout << get<0>(*iter) << " " << get<1>(*iter) << ", ";
        } 
        cout << endl;
    

        //int distancias[cantCiudades + 1];
        //int antecesor[cantCiudades + 1];
        //int cantPremium[cantCiudades + 1];
        //bool rutasprem[cantCiudades + 1];
        //cout << DijkstraLuis(origen,destino,cantCiudades,k,matriz) << endl;
       
        //cout << "Dio esto: " << antecesor[1] <<  antecesor[2] << antecesor[3] << antecesor[4] << endl;
        //cout << "Dio esto: " << rutasprem[1] <<  rutasprem[2] << rutasprem[3] << rutasprem[4] << endl;
        //cout << "Dio esto: " << Dijkstradirijido(origen, destino ,matriz,cantCiudades)<< endl;
    }
  
    cout << "Fin de la ejecucion del algoritmo." << endl;
    return 0;
}



