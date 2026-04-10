#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

const int MAX = 50100; 
const int inf = 0x3f3f3f3f;

int c, v;
vector<vector<pair<int, int>>> g (MAX); 
int dist [MAX][2];  //paridade; 0 -> par, 1 -> impar

void dijkstra (int b, int e){
    for(int i = 0; i < c; i++)  
        for(int j = 0; j < 2; j++)
            dist[i][j] = inf; 

    priority_queue <tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; 
    pq.push({0, b, 0}); dist[b][0] = 0;     

    while(!pq.empty()){
        auto [d, v, p] = pq.top(); pq.pop();
        
        if(dist[v][p] < d) continue; 
        for(auto k : g[v]){
            int np = p ^ 1; 
            if(dist[k.first][np] > d + k.second){
                dist[k.first][np] = d + k.second; 
                pq.push({d + k.second, k.first, np}); 
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
    dijkstra (0, c-1); 
    cout << dist[c-1][0] << " " << dist[c-1][1] << endl; 

}