#include <bits/stdc++.h> 

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std; 
#define inf 0x3f3f3f3f

const int MAX = 510; 
int n, m; 
char M[MAX][MAX]; 
int dist[MAX][MAX]; 
vector<pair<int, int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
pair<int, int> r; 

bool val (pair<int, int> k){
    return k.first >= 0 && k.first < n && k.second >= 0 && k.second < m &&
    M[k.first][k.second] != '#'; 
}

int dijkstra (pair<int, int> s){
    memset(dist, inf, sizeof dist);
    priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; pq.push({0, s}); 
    dist[s.first][s.second] = 0; 
    while(!pq.empty()){
        auto[p, v] = pq.top(); pq.pop(); 
        if(p > dist[v.first][v.second]) continue; 
        if(M[v.first][v.second] == 'E') return dist[v.first][v.second]; 
        for(auto k: mov){
            k.first += v.first, k.second += v.second;            
            if(val(k)){
                int pk = p; 
                if(M[k.first][k.second] >= '1' && M[k.first][k.second] <= '9') pk += M[k.first][k.second] - '0';                            
                if(pk < dist[k.first][k.second]){
                    pq.push({pk, k}); 
                    dist[k.first][k.second] = pk; 
                }
            }
        }
    }
    return dist[r.first][r.second]; 
}

int main (){_
    pair<int, int> s; 
    cin >> n >> m; 
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> M[i][j]; 
            if(M[i][j] == '.') M[i][j] = '0';
            if(M[i][j] == 'H') s = {i, j};
            if(M[i][j] == 'E') r = {i, j};  
        }
    }    
    int ans = dijkstra(s); 
    if(ans == inf) cout << "ARTSKJID" << endl; 
    else cout << ans << endl; 
}
