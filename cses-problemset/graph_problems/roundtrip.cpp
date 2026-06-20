#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 100010

vector<vector<int>> g(MAX); 
int ini, fim; 
vector<int> vis(MAX, 0); 
vector<int> parent(MAX); 
bool dfs (int v, int u){
    vis[v] = 1; 
    parent[v] = u; 
    for(auto k: g[v]){
        if(k == u) continue;
        
        else if(!vis[k]){
            if(dfs(k, v)) return true; 
        }
                   
        else{
            ini = k; 
            fim = v; 
            return true; 
        }
    }
    return false; 
}

int main(){_
    int n, m; cin >> n >> m; 
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; 
        a--, b--; 
        g[a].push_back(b); 
        g[b].push_back(a); 
    }
    int ans = 0; 
    for(int i = 0; i < n; i++){
        if(!vis[i])
            ans = dfs(i, -1);   
        if(ans) break;    
    }
    
    if(!ans) cout << "IMPOSSIBLE" << endl;    
    else{   
        vector<int> ciclo; 
        ciclo.push_back(ini);        
        //1 3 5 1 
        while(fim != ini){
            ciclo.push_back(fim); //parent = {-1, 0, 1, 0, 3}; //1 5 3 1
            fim = parent[fim]; //3 1 -1
        }
        ciclo.push_back(ini); 
        reverse(ciclo.begin(), ciclo.end()); 
        cout << ciclo.size() << endl;
        for(auto k: ciclo) cout << k + 1 << " "; 
        cout << endl; 
    }
    


}