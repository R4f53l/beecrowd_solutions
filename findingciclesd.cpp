#include <bits/stdc++.h> 

using namespace std; 

#define MAX 5

int ciclo = 0; 
vector<int> vis (MAX, 0); 

void dfs(int v, int p, vector<vector<int>> &g){
    vis[v] = 1; 
    for(auto k: g[v]){
        if(!vis[k])
            dfs(k, v, g); 
        else if(vis[k] && k != p)
            ciclo = 1; 
    }
}

int main (){
    vector<vector<int>> g(MAX);
    int arestas; cin >> arestas;  
    for(int i = 0; i < arestas; i++){
        int a, b; cin >> a >> b; 
        g[a - 1].push_back(b - 1); 
        g[b - 1].push_back(a - 1); 
    }

    for(int i = 0; i < MAX; i++){
        if(!vis[i] && !ciclo)
            dfs(i, -1, g);
    }

    cout << ciclo << endl;

}