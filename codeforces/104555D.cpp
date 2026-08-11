#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 310

#define endl '\n'

const int INF = 1e9; 

vector<vector<pair<int, int>>> g(MAX); 
int dist[MAX], dist1[MAX][MAX], dist2[MAX][MAX]; 
int n, m; 

void floyd(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]); 
        }
    }
}

int dijsktra (const int v, const int w){    
    for(int i = 0; i < n; i++)
        dist[i] = INF; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    pq.push({0, v}); 
    dist[v] = 0; 

    while(!pq.empty()){
        auto [d, newv] = pq.top(); pq.pop();     
        if(newv == w) return dist[w];     
        if(d > dist[newv]) continue; 
        for(auto k: g[newv]){    
            if((newv == v && k.second == w) || (newv == w && k.second == v)) continue;            
            if(dist[k.second] > dist[newv] + k.first){                
                dist[k.second] = dist[newv] + k.first; 
                pq.push({dist[newv] + k.first, k.second}); 
            }
        }
    }
    return -1; 

}

int main(){_
    cin >> n >> m; 
    vector<tuple<int, int, int>> entrada; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist1[i][j] = INF, dist2[i][j] = INF;
        }
    }

    for(int i = 0; i < n; i++){
        dist1[i][i] = 0, dist2[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int w, a, b; cin >> a >> b >> w; 
        g[a - 1].push_back({w, b - 1}); 
        g[b - 1].push_back({w, a - 1});         
        dist1[a - 1][b - 1] = w; 
        dist1[b - 1][a - 1] = w; 
        dist2[a - 1][b - 1] = w; 
        dist2[b - 1][a - 1] = w; 
        entrada.push_back({a - 1, b - 1, w}); 
    }    

    

    floyd(); 

    for(auto [a, b, w]: entrada){        
        
        
        if(dist1[a][b] > dist2[a][b]){
            cout << dist2[a][b] << endl; 
            continue;
        }       

        int ans = dijsktra(a, b); 

        if(ans < INF) cout << ans << endl; 
        else cout << "-1" << endl;         

    }


}