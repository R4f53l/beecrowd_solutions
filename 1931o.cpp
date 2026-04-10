#include <bits/stdc++.h> 

using namespace std; 

#define MAX 10010
#define inf 0x3f3f3f3f

vector<vector<pair<int, int>>> g(MAX); 
int dist[MAX][2]; //0 impar, 1 par.
int c, v;
int dijkstra (int v){
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; 
    pq.push({0, v, 1}); //peso, vertice, paridade;
    dist[v][1] = 0; 

    while(!pq.empty()){
        auto[d, ver, p] = pq.top(); pq.pop(); 
        if(ver == c - 1 && p) return dist[ver][p];
        if(d > dist[ver][p]) continue; //se d > dist[ver], ja processei esse vertice 
        for(auto k: g[ver]){
            if(dist[ver][p] + k.second < dist[k.first][p ^ 1]){
                pq.push({dist[ver][p] + k.second, k.first, p ^ 1}); 
                dist[k.first][p ^ 1] = dist[ver][p] + k.second; 
            }
        }

    }
    return -1;
    
}



int main (){
    cin >> c >> v; 
    for(int i = 0; i < v; i++){
        int a, b, w; cin >> a >> b >> w; 
        g[a - 1].push_back({b - 1, w});
        g[b - 1].push_back({a - 1, w});        
    }

    for(int i = 0; i < MAX; i++){
        dist[i][0] = inf, dist[i][1] = inf;
    }
    
    cout << dijkstra(0) << endl;

}