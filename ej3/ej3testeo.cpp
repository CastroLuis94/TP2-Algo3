#include <iostream>
#include <ostream>
#include <vector>
#include <stdio.h>
#include "representador.h"
#include "DSU.h"
#include <chrono>
#include <time.h>
#include <fstream>
#include <sstream>
#include <stdio.h>

#define ya chrono::high_resolution_clock::now




using namespace std;



//me guardo la lista de las aristas en formato(c, c1, c2, e)//las ciudades van de 0 a N-1
list< tuple<int, int, int, int> >  Kruskal(list<tuple<int, int, int, int> >& aristas, int &peso, int &rutas, int n){    
    DisjointSet DisSet(n);//esta en DSU.h Inicio todos los nodos como particiones distintas
    list< tuple<int, int, int, int> > res;
    aristas.sort();//se supone que esto es O(MlogM)= O(n^2 log(n^2)) = O(n^2 2log(n)) = O(n^2 log(n)) 
    for(list< tuple<int, int, int, int> >::iterator it = aristas.begin(); it != aristas.end(); it++){ 
        if (DisSet.find(get<1>(*it)-1) != DisSet.find(get<2>(*it)-1)){//si estan en != particion no forman ciclos, y es el menor por recorrer en orden          
            res.push_back(*it);
            rutas++;            
            if(!(get<3>(*it))){
                peso = peso + get<0>(*it);   //si no existia, sumo el costo de construir la ruta             
            }            
            DisSet.Nunion(get<1>(*it)-1, get<2>(*it)-1); //Nunion en DSU.h, uno las particiones.            
        }else{
            if((get<3>(*it))){
                peso = peso - get<0>(*it);//si existe la ruta los costos son negativos.(por eso resto)
            }
        }
    }   
    return res;
}

/*Recorro la lista de manera ordenada.(aristas ordenadas por costo, si existen tienen costo negativo(al
levantar entrada lo veo)), si no existen el costo es positivo*/




// acomodarAristas me deja list<tuple<c1,c2> >(aristas)
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
     char buffer[300]={0};   // lo usaremos para guardar el nombre del fichero
    
    
    sprintf(buffer, "ejercicio3_test1.csv"); // Ahora tenemos en buffer = "holaXX.txt"       
    vector<int> archivo;
      
    ofstream salida;
    salida.open(buffer, ios::out);
    

    if(salida.fail()){
        cerr << "No se abrio bien el archivo" << endl;
        exit(1);
    }
    salida << "Ciudades, tiempo1\n";

    while(true){
        vector< vector<int> > res;
        //cout << "ingrese la cantidad de ciudades" <<endl;
        int cantCiudades;
        cin >> cantCiudades;
        // n es la candidad de ciudades
        if(cantCiudades == -1){
            //salida.close();
            break;
        }
        int cantRutas = (cantCiudades*(cantCiudades-1))/2;
        

        //cout << "Ingrese las " << cantRutas << " rutas en formato: numero_ciudad1 numero_ciudad2 es_premium(0 o 1) distancia" <<endl;

        list<tuple<int, int, int, int > > aristas = listaAristas(cantRutas);  //listaAristas en aux.h      
         //Me guardo la lista de las aristas en formato(c, c1, c2, e). 

        /*Uso un listaAristas en vez de la ListadeAdjacencia porque:
         si no deberia definir operator < de Dato, y porque necesito la lista de aristas
        (y en listadeIncididencia deberia devolver vector< tuple<Dato, int, int> >) puesto que necesito
        tener el Dato(y en su operator <, el costo) primero para ordenar bien las aristas.
        Debido a todos estos problemas list<tuple<int, int, int, int> >resulta mas comodo(puede ser vector
         en vez de lista) */ 
        auto start = ya();     
        int peso = 0;
        int rutas = 0;            
        list<tuple<int, int, int, int> > resultado = Kruskal(aristas,  peso,  rutas, cantCiudades);       
        //salida << cantCiudades  << ";" <<chrono::duration_cast<chrono::nanoseconds>(end-start).count() << endl;
        list<tuple<int, int> > aristassolucion = acomodarAristas(resultado);        
        //el resultado de Kruskal es una list<tuple<c, c1, c2, e> >, acomodarAristas me deja list<tuple<c1,c2> >(aristas)
        auto end = ya();
        archivo.push_back(chrono::duration_cast<chrono::nanoseconds>(end-start).count());
        cout<< peso <<" "<< rutas << " ";
        int i =1;
        for(list<tuple<int, int> >::iterator iter = aristassolucion.begin(); 
        iter != aristassolucion.end(); iter++){
        cout << "c"<<i << get<0>(*iter) << " " << "c"<< i <<get<1>(*iter) << " ";
        i++;
        } 
        cout << endl;
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
    //cout << "Fin de la ejecucion del algoritmo." << endl;
    return 0;
}



