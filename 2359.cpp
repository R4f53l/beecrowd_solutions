#include <bits/stdc++.h> 

using namespace std; 

#define INF 0x3f3f3f3f

const int MAX = 1e3 + 1; 

void dijkstra (int x, vector<int> &dist, vector<vector<pair<int, int>>> &g){
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, x}); dist[x] = 0; 
    while(!pq.empty()){
        int d = pq.top().first, v = pq.top().second; pq.pop(); 
        if(d > dist[v]) continue;         
        for(auto k: g[v]){
            int dk = k.first + d; 
            if(dk < dist[k.second]){
                pq.push({dk, k.second});
                dist[k.second] = dk; 
            }
        }
    }
    
    
}

int main (){
    int n, m, q; 
    while(cin >> n >> m >> q){    
        vector<vector<pair<int, int>>> g (MAX);
        vector<int> dist (MAX, INF); 
        for(int i = 0; i<m; i++){
            int a, b, w; cin >> a >> b >> w; 
            g[a-1].push_back({w, b-1});
            g[b-1].push_back({w, a-1});
        }
        int ans = -INF; 
        for(int i = 0; i<q; i++){
            int x; cin >> x; 
            dijkstra(x-1, dist, g);                  
        }
        for(int i = 0; i<n; i++)
            ans = max(ans, dist[i]);    

        cout << ans << endl; 

    }
}