#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define MAX 50100
#define INF 0x3f3f3f3f
vector<vector<pair<int, int>>> g(MAX); 
vector<int> dist (MAX, INF); 
int c, v, cont = 0; 

void dijkstra (int origem, int destino){
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; pq.push({origem, 0}); 
    dist[origem] = 0; 
    while(!pq.empty()){
        auto v = pq.top(); pq.pop(); 
        if (v.first == destino) return; 
        if (dist[v.first] < v.second) continue; 
        for(auto k : g[v.first]){
            if(dist[k.first] > (v.second + k.second)){
                dist[k.first] = v.second + k.second; 
                pq.push({k.first, v.second + k.second}); 
                cont++; 
            }
        }
    }
}

int main (){_
    cin >> c >> v; 

    for(int i = 0; i < v; i++){
        int a, b, p; cin >> a >> b >> p; 
        g[a-1].push_back({b-1, p}); 
        g[b-1].push_back({a-1, p}); 
    }

    dijkstra(0, c-1); 
    
    if((cont % 2) || dist[c-1] == INF) cout << "-1" << endl; 
    else cout << dist[c-1] << endl;
}