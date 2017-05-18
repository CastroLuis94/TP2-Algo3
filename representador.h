#include <iostream>
#include <ostream>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include <tuple>
#include "aux.h" 
#include <list>
using namespace std;

struct Dato{
    int distancia;
    bool caminoPremium;
    Dato(){
        distancia = -1;
        caminoPremium = false;
    }
    Dato(int d,bool cP){
        distancia = d;
        caminoPremium = cP;
    }
};

void mostrar(Dato t) {
    cout << "(d:" << t.distancia << ",p:" << t.caminoPremium << ")";  
}

void mostrar(vector<Dato> vs){
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

void mostrar(vector<vector<Dato> > vs){
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



void mostrar(vector<tuple <int,int,Dato> > ts){
    int i = 0;
    cout << "[";
    while( i < ts.size()){
        cout << "(" << (get<0>(ts[i])) << "," << (get<1>(ts[i])) << ",";
        mostrar(get<2>(ts[i]));
        cout << ")";
        i++;
        if(i < ts.size()){
            cout << ",";
        }
    }
    cout << "]"<<endl;
}



vector<int> crearFilaEnteros(int M){
    int i = 0;
    vector<int> res;
    while(i < M){
        res.push_back(INT_MAX);
        i++;
    }
    return res;
}

vector<vector< int > > matrizEnteros(int N, int M){
    int i = 0;
    vector<vector<int> > res;
    vector<int> fila = crearFilaEnteros(M+1);
    while(i <= N){
        res.push_back(fila);
        i++;
    }
    return res;
}
vector<bool> crearFilaBooleanos(int M){
    int i = 0;
    vector<bool> res;
    while(i < M){
        res.push_back(false);
        i++;
    }
    return res;
}

vector<vector< bool > > matrizBooleana(int N, int M){
    int i = 0;
    vector<vector<bool> > res;
    vector<bool> fila = crearFilaBooleanos(M+1);
    while(i <= N){
        res.push_back(fila);
        i++;
    }
    return res;
}

vector<Dato> crearFilaDatos(int M){
    int i = 0;
    vector<Dato> res;
    while(i < M){
        res.push_back(Dato());
        i++;
    }
    return res;
}

vector<vector< Dato > > matrizDatos(int N, int M){
    int i = 0;
    vector<vector<Dato> > res;
    vector<Dato> fila = crearFilaDatos(M+1);
    while(i <= N){
        res.push_back(fila);
        i++;
    }
    return res;
}

int d(Dato t) {
    return t.distancia;  
}

bool premium(Dato t) {
    return t.caminoPremium;  
}

class Representador{
    public:
        Representador(int N, vector<vector< int > > entrada){
            _listaEntrada = entrada;
            _cantCiudades = N;
        }
        
        vector< tuple<int,int,Dato> > listaDeIncidencia();
        vector< vector<Dato> > matrizAdyacencia();
        vector < vector<tuple <int,Dato> > > listaDeAdyacencia();
    private:
        vector<vector<int> > _listaEntrada;
        int _cantCiudades;
};

vector<tuple<int,int,Dato> > Representador::listaDeIncidencia(){
    int i = 0;
    vector<tuple <int,int,Dato> > res;
    while(i < _listaEntrada.size()){
        tuple<int,int,Dato> t;
        bool premium;
        if(_listaEntrada[i][2]==1){
            premium = true;
        }else{
            premium = false;
        }
        get<0>(t) = _listaEntrada[i][0];
        get<1>(t) = _listaEntrada[i][1];
        get<2>(t) = Dato(_listaEntrada[i][3],premium);
        res.push_back(t);
        i++;
    }
    return res;
}

vector<vector <Dato> > Representador::matrizAdyacencia(){
    int N = _cantCiudades;
    vector < vector <Dato> > res = matrizDatos(N,N);
    int i = 0;
    vector< vector<int> >& vs = _listaEntrada;
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
        res[ciudad1][ciudad2] = Dato(distancia,hayCaminoPremium);
        res[ciudad2][ciudad1] = Dato(distancia,hayCaminoPremium);        
        // Nota importante, estoy asumiendo que si hay camino de A a B entonces hay camino de B a A y tiene la misma distancia,
        //capaz estoy flasheando
        i++;
    }
    for(int n = 0; n < N+1; n++){
        res[n][n] = Dato(0, false);
    }
    return res;
}

vector < vector<tuple <int,Dato> > > Representador::listaDeAdyacencia(){
    int cont = 0;
    int contcaminos =0;
    vector < vector <tuple <int,Dato> > > res;
    res.resize(_cantCiudades);
    while(cont < _listaEntrada.size()){
        tuple <int,Dato> t;
        bool premium;
        if(_listaEntrada[cont][2]==1){
            premium = true;
        }else{
            premium = false;
        }
        int i = _listaEntrada[cont][0];
        get<0>(t) = _listaEntrada[cont][1];
        get<1>(t) = Dato(_listaEntrada[cont][3],premium);
        res[i].push_back(t);
        cont++;
    }
    return res;
}
void mostrar(vector< vector <tuple <int,Dato> > > ts){
    int i = 0;
  //  cout << "[";
    while( i < ts.size()){
        cout << "Caminos de ciudad " << i << ":"<< "(" ; 
        int j = 0;
        if (ts[i].size() == 0){
            cout << ")";
        }
        while( j < ts[i].size()) {
            cout << "(" << (get<0>(ts[i][j])) << ",";
            mostrar(get<1>(ts[i][j]));
            cout << ")";
            j++;
        }
        i++;
        cout << endl;
    }
  //  cout << "]"<<endl;
}


void agregarLindantes(vector<vector<Dato> >& matrizEntrada,list<tuple<int,int,int,int> >& ls,tuple<int,int,int,int> t){
    int ciudad = get<0>(t);
    int dondeVengo = get<1>(t);
    int i = 0;
    int cantidadDePremiumUsados = get<2>(t);
    int distanciaRecorrida = get<3>(t);
    while(i < (matrizEntrada[ciudad]).size()){
        Dato datosCiudad = matrizEntrada[ciudad][i];
        if (datosCiudad.distancia != -1 and i != dondeVengo){
            int distancia = datosCiudad.distancia+distanciaRecorrida;
            int premium;
            if (datosCiudad.caminoPremium){
                premium = cantidadDePremiumUsados + 1;
            }else{
                premium = cantidadDePremiumUsados;
            }
            ls.push_back(make_tuple(i,ciudad,premium,distancia));
        }
        i++;
    }
   

}
