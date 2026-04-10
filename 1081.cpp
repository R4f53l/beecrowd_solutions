#include <bits/stdc++.h> 

using namespace std; 


void DFS (vector<vector<int>> adj, vector<int>&visitados, int vertice){
    visitados[vertice] = 1; 
    for(auto v:adj[vertice]){
        cout << vertice; 
        if(!visitados[vertice]){
            printf("pathR(G, %d)", v);
            DFS(adj, visitados, v);
        }
        else cout << v; 
    }
}

int main () {
    int n; 
    cin >> n; 
    while(n--){
        int v, e; 
        cin >> v >> e; 
        vector <vector<int>> adj; 
        vector <int> visitados(0, v); 
        adj.resize(v);
        while(e--){
            int a, b; 
            cin >> a >> b; 
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        DFS(adj, visitados, 0);
    }
    
}