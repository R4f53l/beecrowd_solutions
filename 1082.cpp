#include <bits/stdc++.h> 

using namespace std; 

const int MAX = 27;



void DFS (int v, vector<bool> &vis, vector<int> &l, vector<vector<int>>adj){
    vis[v] = true; 
    l.push_back(v);
    for(auto w: adj[v]){
        if(!vis[w]){
            DFS(w, vis, l, adj);
        }
    }
}


int main (){
    int n, caso = 1, first = 1; 
    cin >> n; 
    while(n--){
        int v, e; 
        cin >> v >> e; 
        vector<vector<int>> adj(MAX);
        vector<bool> vis(MAX);

        for(int i = 0; i<e; i++){
            char a, b; cin >> a >> b;
            adj[a-97].push_back(b-97);
            adj[b-97].push_back(a-97);
        }
        
        
        
        printf("Case #%d:\n", caso++);
        
        int c = 0; 
        for(int i = 0; i<v; i++){
            vector<int> l;
            if(!vis[i]){
                c++;
                DFS(i, vis, l, adj);
                sort(l.begin(), l.end());
                for(int t = 0; t<l.size(); t++) printf("%c,", l[t] + 97);
                cout << endl;
            }
        }
        
        
        printf("%d connected components\n", c);
        printf("\n");
        
    }
}