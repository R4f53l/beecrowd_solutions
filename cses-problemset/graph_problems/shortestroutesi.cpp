#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 100500
int n, m;
vector<vector<pair<long long, int>>> g(MAX);

vector<long long> dist(MAX, 0x3f3f3f3f3f3f3f3f);

void dijkstra(int v){
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; 
    pq.push({0, v});
    dist[v] = 0; 
    while(!pq.empty()){
        auto [w, v] = pq.top(); pq.pop();           
        if(dist[v] < w) continue; 
        for(auto [p, nv]: g[v]){
            if(dist[nv] > p + w){
                pq.push({p + w, nv});
                dist[nv] = p + w; 
            }
        }
    }
}

int main(){_
    cin >> n >> m;  
    //complexidade (v + e) log(v) -> p 10^5 ta safe...
    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w; 
        g[a - 1].push_back({w, b - 1});        
    }    
    

    dijkstra(0);

    

    for(int i = 0; i < n; i++)
        cout << dist[i] << " "; 
    cout << endl;

}