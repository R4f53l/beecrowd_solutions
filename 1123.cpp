#include <bits/stdc++.h> 

using namespace std; 
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define MAX 300
#define INF 0x3f3f3f3f
vector<vector<pair<int, int>>> g (MAX); 

vector<int> ant = {-1};  
int n; 

int dijkstra (int origem, int destino){
    vector<int> dist (MAX, INF); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; pq.push({origem, 0}); 
    dist[origem] = 0; 
    int r = 0; 
    while(!pq.empty()){
        auto v = pq.top(); pq.pop(); 
        
        if(dist[v.first] < v.second) continue; 
        if(v.first == destino) return dist[v.first]; 
        for(auto k: g[v.first]){
            if(v.first == (ant[ant.size()-1] + 1)) cout << "oi" << endl;
            else if (dist[k.first] > (k.second + v.second)){
                dist[k.first] = k.second + v.second; 
                ant.push_back(k.first); 
                pq.push({k.first, k.second + v.second}); 
            }
        }
    }
    return INF; 
}

int main (){
    int m, c, k; 
    while(cin >> n >> m >> c >> k, n){
        for(int i = 0; i < m; i++){
            int a, b, p; cin >> a >> b >> p; 
            g[a].push_back({b, p}); 
            g[b].push_back({a, p}); 
        }
        
        cout << dijkstra(c-1, n-1) << endl; 
        
    }
    
    
}