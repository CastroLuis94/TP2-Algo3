//This union-find class implements two optimization ideas:
//1)path compression
//2)union by rank
#include <iostream>
#include <ostream>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include <tuple> 
#include <list>
using namespace std;


class DisjointSet{
    public:
    DisjointSet(int N);
    int find(int element);
    void union();
    private:
    vector<int> rank_;
    vector<int> padre_;    

};

DisjointSet::DisjointSet(int N):
    rank_(N, 0), padre_(N)
{
    for(int i = 0; i < N; i++ ){        
        padre_[i] = i;
    }
}

int DisjointSet::find(int element){
    if (padre_[element] != element){
        padre_[element] = find(padre_[element]);        
    }
    return padre_[element];
}

void DisjointSet::union(int a, int b){

    a = find(a);
    b = find(b);
    // Tomo los representantes de cada conjunto
    if(rank_[a] < rank_[b]){
        padre_[a] = b;
    }else{//<=        
        padre_[b] = a;
    }
    if(rank_[a] = rank_[b]){
        rank_[a] = rank_[a] + 1;
    }
}

