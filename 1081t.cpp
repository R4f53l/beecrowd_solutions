#include <bits/stdc++.h> 

using namespace std; 

const int MAX = 21; 

bool vis [MAX]; 

void dfs (int x, vector<vector<int>> adj){
    cout << x << "-"; 
    vis[x] = 1; 
    for(auto k: adj[x]){
        cout << k << " pathR(G," << k << ")" << endl;
        dfs(k, adj);
    }
}

int main (){
    int n; cin >> n; 
    while(n--){
        int v, e; cin >> v >> e; 
        vector<vector<int>> adj(v);
        for(int i = 0; i<e; i++){
            int a, b; cin >> a >> b; 
            adj[a].push_back(b);
        }
        memset(vis, 0, sizeof vis);
        for(int i = 0; i<v; i++){
            if(vis[i]) dfs(i, adj); 
            cout << endl; 
        }
    }
}