#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 1010
#define inf 0x3f3f3f3f

int c, r, e; 
vector<int> dist (MAX, -1);
vector<vector<int>> g(MAX); 

void bfs (int v){
    queue<int> q; q.push(v); dist[v] = 0; 

    while(!q.empty()){
        int k = q.front(); q.pop(); 
        for(auto t: g[k]){
            if(dist[t] == -1){
                q.push(t); dist[t] = dist[k] + 1; 
            }
        }
    }

    



}

int main (){
    int n, m; 
    
    while(cin >> n >> m){ 
        g.clear(); 
        dist.assign(n, -1);
        g.resize(n);
        
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b; 
            g[a - 1].push_back(b - 1); 
            g[b - 1].push_back(a - 1);
        }
    
        cin >> c >> r >> e; 
        c--, r--, e--;
        dist[e] = inf; 
        
        bfs(r);
        
        cout << dist[c] << endl;
    }



}