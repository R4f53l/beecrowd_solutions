#include <bits/stdc++.h> 

using namespace std; 

#define inf 0x3f3f3f3f3f3f3f3f
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define MAX 5

int main (){_
    long long dist[MAX][MAX] = {}; 
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            if(j != i) dist[i][j] = inf;
    }

    int arestas; cin >> arestas; 
    for(int i = 0; i < arestas; i++){
        int a, b, w; 
        dist[a][b] = min(dist[a][b], (long long) w); 
    }

    
        
}