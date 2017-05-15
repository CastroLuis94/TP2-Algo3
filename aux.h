#include <iostream>
#include <ostream>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include <tuple>

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

