#include <bits/stdc++.h> 

using namespace std; 
#define MAX 10010
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
vector<vector<int>> g(MAX); 
vector<int> vis, instack; 

bool dfs(int v){
    instack[v] = 1, vis[v] = 1; 
    for(auto k: g[v]){
        if(!vis[k]){
            if(dfs(k)) return true; //se alguem encontrou um ciclo, então ha um ciclo
            //ao quebrarmos a chamada por ter achado um ciclo, a funcao retonra justamente pra linha posterior à chamada;
        }
        else if(vis[k] && instack[k])
            return true;  
    }
    instack[v] = 0;
    return false; 
}

int main (){_
    int t; cin >> t; 
    while(t--){
        int d, p; cin >> d >> p; 
        g.assign(d, vector<int>());
        vis.assign(d, 0);
        instack.assign(d, 0);
        for(int i = 0; i < p; i++){
            int a, b; cin >> a >> b; 
            g[a - 1].push_back(b - 1); 
        }
        bool ans = false;  
        for(int i = 0; i < d; i++){
            if(!vis[i]){
                ans = dfs(i); 
                if(ans) break;
            }
        }
        cout << (ans ? "SIM" : "NAO") << endl;
    }
}