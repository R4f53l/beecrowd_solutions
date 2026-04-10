#include <bits/stdc++.h> 

using namespace std; 

#define MAX 2020
vector<vector<int>> g(MAX); 
vector<int> vis(MAX, 0); 

void dfs (int v){
    vis[v] = 1; 
    for(auto k: g[v]){
        if(!vis[k])
            dfs(k);
    }
}

int main (){
    int n, m; 
    while(cin >> n >> m, n){
        int v; 
        for(int i = 0; i < m; i++){
            int a, b, p; cin >> a >> b >> p; 
            g[a - 1].push_back(b - 1); 
            v = a - 1; 
            if(p > 1) g[b - 1].push_back(a - 1); 
        }

        
        int ans = 1; 
        for(int i = 0; i < n; i++){
            dfs(i);
        }

        cout << ans << endl;
    }
}