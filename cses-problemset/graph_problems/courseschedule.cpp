#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 100010

vector<vector<int>> g(MAX); 
vector<int> vis(MAX);
vector<int> pilha(MAX); 
vector<int> ans; 
bool dfs (int v){
    vis[v] = 1; 
    pilha[v] = 1; 
    for(auto k: g[v]){
        if(!vis[k]){
            if(dfs(k)) return true;  
        }        
        else if(pilha[k] && vis[k]) return true;      
    }
    //terminei a recursão desse cara 
    ans.push_back(v); 
    pilha[v] = 0; 
    return false; 
}

int main(){_
    int n, m; cin >> n >> m; 
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; 
        a--, b--; 
        g[a].push_back(b); 
    }
    bool a = 0; 
    for(int i = 0; i < n; i++){
        if(!vis[i])
            a = dfs(i); 
        if(a) break;
    }
    
    reverse(ans.begin(), ans.end()); 

    if(a)
        cout << "IMPOSSIBLE" << endl; 
    else
        for(auto k: ans) cout << k + 1 << " "; 
    cout << endl; 


}