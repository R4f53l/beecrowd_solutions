#include <bits/stdc++.h>

using namespace std; 

int main (){
    int n = 4; 
    vector<tuple<int, int, int>> g(n); //a, b, peso
    int arestas = 4; 
    for(int i = 0; i < 4; i++){
        int a, b, w; cin >> a >> b >> w; 
        g[i] = {a-1, b-1, w}; 
    }

    vector<int> dist(n, 0x3f3f3f3f); 
    dist[0] = 0; 
    for(int i = 0; i <= n - 1; i++){
        for(auto [a, b, w]: g)
            dist[b] = min(dist[a] + w, dist[b]);         
    }
    
    cout << dist[1] << endl; 
    

}