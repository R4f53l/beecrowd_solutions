#include <bits/stdc++.h> 

using namespace std; 

const int MAX = 1e5 + 10;

vector<vector<int>> g(MAX);
bool vis [MAX]; 
vector<int> pai(MAX, -1);

void bfs (int x){
    queue <int> q; q.push(x); 
    vis[x] = 1; pai[x] = x; 
    while(!q.empty()){
        int v = q.front(); q.pop(); 
        for(auto k: g[v]){
            if(!vis[k]){
                q.push(k); 
                vis[k] = 1; pai[k] = v;               
            }
        }
    }
}

vector<int> path (int s){
    vector<int> ans; 
    if(!vis[s]) return ans; 
    while(pai[s] != s){
        ans.push_back(s);
        s = pai[s];         
    }
    return ans; 
}

int main (){
    int n, m; cin >> n >> m;     

    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b; 
        g[a-1].push_back(b-1); 
        g[b-1].push_back(a-1);
    }

    bfs(0); 
    vector<int> ans = path(n-1); 
    if(ans.size()){
        cout << ans.size() << endl; 
        for(auto k: ans) cout << k << " "; 
    }
    else cout << "Impossible" << endl;
    
    

    

}