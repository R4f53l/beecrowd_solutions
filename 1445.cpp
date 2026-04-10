#include <bits/stdc++.h> 

using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MAX = 1e3 + 1; 

int c = 1; 

void dfs (int s, vector<bool> &vis, vector<vector<int>> &adj){
    vis[s] = 1; 
    for(auto k: adj[s]){ // 1 2    2 1 3  4 5 
        if(!vis[k]){
            c++; 
            dfs(k, vis, adj);
        }
    }

}

int main (){_
    int n; 
    while(scanf("%d", &n), n){
        
        vector<bool> vis(MAX);
        vector<vector<int>> adj (MAX);
        for(int i = 0; i<n; i++){
            int a, b; scanf(" (%d,%d)", &a, &b);
            
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        dfs(0, vis, adj);
        printf("%d\n", c); 
        c = 1; 
    }
    

}