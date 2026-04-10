#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);



void dfs (int x, vector<vector<int>> &g, int *vis, int *instack, int &p){    
    vis[x] = 1; 
    instack[x] = 1; 
    for(auto k: g[x]){
        if(!vis[k]) dfs(k, g, vis, instack, p); 
        else if(instack[k]) p = 1;  
    }
    instack[x] = 0; 
    
}

int main (){_
    int n; cin >> n; 
    while(n--){
        int v, e, p = 0; cin >> v >> e; 
        vector<vector<int>> g(v);
        int vis [v] = {}, instack[v] = {};
        for(int i = 0; i<e; i++){
            int a, b; cin >> a >> b; 
            g[a-1].push_back(b-1);
        }
        for(int i = 0; i<v; i++){
            if(!vis[i]) dfs(i, g, vis, instack, p);
            
        }
        if(p) cout << "SIM" << endl; 
        else cout << "NAO" << endl; 
    }
}