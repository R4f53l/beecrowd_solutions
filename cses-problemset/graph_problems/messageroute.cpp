#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 100110
vector<vector<int>> g(MAX);
vector<int> vis(MAX, 0), pai(MAX); 

void bfs(int v){
    queue<int> q; q.push(v);
    vis[v] = 1;
    pai[v] = v; 
    while(!q.empty()){
        int v = q.front(); q.pop(); 
        for(auto k: g[v]){
            if(!vis[k]){
                q.push(k); 
                pai[k] = v;
                vis[k] = 1; 
            }
        }
    }
}

int main(){_
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    n--;
    bfs(0);

    if(!vis[n]){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int cont = 1; 
    vector<int> ans; 
    ans.push_back(n); 
    while(n != pai[n]){
        cont++; 
        n = pai[n];
        ans.push_back(n);         
    }
    cout << cont<< endl;
    reverse(ans.begin(), ans.end()); 
    for(auto k: ans) cout << k + 1 << " ";
}