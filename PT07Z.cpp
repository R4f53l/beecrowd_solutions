#include <bits/stdc++.h> 

using namespace std; 

#define inf 0x3f3f3f3f

const int MAX = 1e3 + 10;


vector<vector<int>> g(MAX); 
int dist[MAX]; 

void dfs (int x){     
    for(auto k: g[x]){
        if(dist[k] == -1){
            dist[k] = dist[x] + 1; 
            dfs(k);
        }
    }
}

int main (){
    int v; cin >> v; 
    for(int i = 0; i<v-1; i++){
        int a, b; cin >> a >> b; 
        g[a-1].push_back(b-1); g[b-1].push_back(a-1);
    }
    
    int ind, distmax = -inf; 
    memset(dist, -1, sizeof(dist));
    dist[0] = 0; 
    dfs(0); 
    for(int i = 0; i<v; i++){
        if(dist[i] > distmax){
            ind = i; distmax = dist[i]; 
        }
    }
    
    memset(dist, -1, sizeof(dist));
    dist[ind] = 0; dfs(ind); 
    int ans = -inf; 
    for(int i = 0; i<v; i++)
        ans = max(ans, dist[i]); 
    
    cout << ans << endl; 
}