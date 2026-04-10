#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
const int MAX = 1e6;

int dist [MAX]; 

void dijkstra (int x, vector<vector<pair<int, int>>> g, vector<int> &dist){
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; pq.push({0, x});
    dist[x] = 0; 
    while(!pq.empty()){
        int v = pq.top().second, d = pq.top().first; pq.pop();
        if(d > dist[v]) continue; 
        for(auto k: g[v]){
            int dk = d + k.first; 
            if(dk < dist[k.second]){
                pq.push({dk, k.second});
                dist[k.second] = dk; 
            }
        }
    }

}

int main(){_
    int n, e, first = 0; 
    while(cin >> n >> e, n){
        vector<vector<pair<int, int>>> g (n);
        
        for(int i = 0; i<e; i++){
            int x, y, h; cin >> x >> y >> h;
            if(!i) g[x-1].push_back({h, y-1}); //1 2 2 1
            else {
                int p = 0; 
                for(auto &k: g[y-1]){                    
                    if(k.second == x-1){
                        g[x-1].push_back({0, y-1});
                        k.first = 0; 
                        p = 1; 
                        break;
                    }
                }
                if(!p) g[x-1].push_back({h, y-1});                
            }
        }        
        int k; cin >> k;          
        for(int i = 0; i<k; i++){
            int o, d; cin >> o >> d; 
            vector<int> dist (n, INF);
            dijkstra(o-1, g, dist);            
            if(dist[d-1] != INF) cout << dist[d-1] << endl; 
            else cout << "Nao e possivel entregar a carta" << endl; 
        }
        cout << endl; 

    }
}