#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 7
vector<vector<int>> g(MAX), gt(MAX), cc; 
vector<int> vis(MAX, 0), c; 
stack<int> s; 

void dfs (int v){
    vis[v] = 1; 
    for(auto k: g[v]){
        if(!vis[k]) dfs(k);
    }
    s.push(v); 
}

void dfs1 (int v){
    vis[v] = 1; 
    for(auto k: gt[v]){
        if(!vis[k])
            dfs1(k); 
    }
    c.push_back(v); 
}


int main (){

    int arestas; cin >> arestas; 
    for(int i = 0; i < arestas; i++){
        int a, b; cin >> a >> b; 
        g[a - 1].push_back(b - 1); 
    }

    for(int i = 0; i < MAX; i++){
        if(!vis[i]) dfs(i); 
    }

    //transpor o grafo: 
    for(int i = 0; i < MAX; i++){
        for(auto k: g[i])
            gt[k].push_back(i);         
    }

    vis.assign(MAX, 0); 

    while(!s.empty()){
        int v = s.top(); s.pop(); 
        cout << v << " "; 
        if(vis[v]) continue; 
        dfs1(v); 
        cc.push_back(c); c.clear(); 
    }
    
    cout << endl;

    for(auto k: cc){
        for(auto i: k) cout << i + 1<< " ";
        cout << endl;
    }


}