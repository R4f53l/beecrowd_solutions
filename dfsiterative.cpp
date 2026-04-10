#include <bits/stdc++.h> 

using namespace std; 

#define N 5

vector<vector<int>> g(N); 
vector<int> vis(N, 0);

void dfs (int v){
    stack<int> p; 
    p.push(v); vis[v] = 1; 
    while(!p.empty()){
        int k = p.top(); p.pop();
        cout << k << " "; 
        for(auto t: g[k]){
            if(!vis[t]){
                p.push(t);
                vis[t] = 1; 
            }
        }
    }
}

int main (){
    int arestas; cin >> arestas; 
    for(int i = 0; i < arestas; i++){
        int a, b; cin >> a >> b; 
        g[a - 1].push_back(b - 1); 
        g[b - 1].push_back(a - 1); 
    }
    dfs(0); 

}