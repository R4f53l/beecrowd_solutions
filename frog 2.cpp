#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);

#define INF 0x3f3f3f3f

const int MAX = 1e3; 

vector<int> dist (MAX, INF); 
vector<vector<pair<int, int>>> g (MAX);

void dijkstra (int x){
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    pq.push({0, x}); dist[x] = 0; 
    while (!pq.empty()){
        auto [d, v] = pq.top(); pq.pop(); 
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

int main () {_
    int n, k; cin >> n >> k; 
    
    vector<int> h (n);
    for(int i = 0; i<n; i++)
        cin >> h[i];     

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<= i + k && j<n; j++)
            g[i].push_back({abs(h[i] - h[j]), j});        
    } 
    
    dijkstra (0); 
    cout << dist[n-1] << endl; 


    return 0; 
}