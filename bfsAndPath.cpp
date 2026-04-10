#include <bits/stdc++.h> 

using namespace std; 

const int MAX = 1e5 + 10;

vector<vector<int>> adj(MAX); 
vector<bool> vis (MAX);
vector<int> pai (MAX);

void BFS (int s){
    queue <int> q; 
    q.push(s), vis[s] = 1, pai[s] = s; 

    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto k: adj[v]){
            if(!vis[k]){
                q.push(k);
                vis[k] = 1; 
                pai[k] = v; 
            }
        }
    }

}

vector <int> path (int v){
    vector<int> ret; 
    if(!vis[v]) return ret; 
    ret.push_back(v);
    while(pai[v] != v){
        v = pai[v];
        ret.push_back(v);
    }
    reverse(ret.begin(), ret.end());
    return ret; 
}

int main () {
    int n, m; cin >> n >> m; 

    for(int i = 0; i<n; i++){
        int a, b; cin >> a >> b; 
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    BFS(0);
    vector<int> c = path(n-1);
    if(!c.size()) cout << "IMPOSSIBLE" << endl;
    else {
        cout << c.size() << endl;
        for(auto k: c) cout << k+1 << " ";
        cout << endl;        
    }
    
}