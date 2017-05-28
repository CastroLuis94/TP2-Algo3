#include <iostream>
#include <ostream>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include <tuple>
#include <list>

using namespace std;



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


list<tuple<int, int, int, int> > listaAristas(int cantRutas){
    int i = 0;
    list<tuple< int, int, int, int > > res;//la arista es un vector.
    for(int i =0; i< cantRutas; i++){
        tuple<int, int, int, int> camino;
        int ciudad1;
        cin >> ciudad1;
        int ciudad2;
        cin >> ciudad2;
        int existencia;
        cin >> existencia;        
        int costo;
        cin >> costo;
        if(existencia){
            get<0>(camino) = -1*(costo);         
        }else{
            get<0>(camino) = (costo);
        }
        get<1>(camino) = (ciudad1);
        get<2>(camino) = (ciudad2);
        get<3>(camino) = (existencia);
        res.push_back(camino);        
    }
    return res;
}
//listaArista me guarda la lista de las aristas en formato(c, c1, c2, e)









//yo quiero una lista de aristas.

