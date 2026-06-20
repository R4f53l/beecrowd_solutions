#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 100010

vector<vector<int>> g(MAX); 
vector<int> color(MAX, 0); 

bool dfs (int v, int c){
    color[v] = c;
    for(auto k: g[v]){
        if(!color[k]){
            if(!dfs(k, 3 - c))
                return false; 
        }
        else if(color[k] == color[v]) return false; 
    } 
    return true; 
}

int main(){_
    int n, m; cin >> n >> m; 
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; 
        a--, b--; 
        g[a].push_back(b); 
        g[b].push_back(a); 
    }
    bool ans = 1; 
    for(int i = 0; i < n; i++){
        if(!color[i])
            ans = dfs(i, 1);
        if(!ans) break; 
    }
    if(!ans) cout << "IMPOSSIBLE" << endl; 
    else for(int i = 0; i < n; i++)  cout << color[i] << " "; 
}