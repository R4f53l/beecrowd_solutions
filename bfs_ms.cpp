#include <bits/stdc++.h> 

using namespace std; 

const int MAX = 1010;
char M[MAX][MAX]; 
int n, m;
int dist [MAX][MAX], vis[MAX][MAX];
vector<pair<int, int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


bool val (pair<int, int> k){
    return k.first >= 0 && k.second >= 0 && k.first < n 
    && k.second < m && M[k.first][k.second] == '.' && 
    !vis[k.first][k.second]; 
}

void bfs_ms (vector<pair<int, int>> ms){
    memset(vis, 0, sizeof vis);
    memset(dist, -1, sizeof dist);

    queue <pair<int, int>> q; 
    for(auto k: ms){
        q.push(k);
        vis[k.first][k.second] = 1; 
        dist[k.first][k.second] = 0;
    }

    while(!q.empty()){
        pair<int, int> v = q.front(); q.pop();
        for(auto k: mov){
            k.first += v.first, k.second += v.second; 
            if(val(k)){
                vis[k.first][k.second] = 1; 
                dist[k.first][k.second] = dist[v.first][v.second] + 1;
                q.push(k);
            }
        }
    }

}

int bfs (pair<int, int> s){
    memset(vis, 0, sizeof vis);
    
    queue <pair<int, int>> q; 
    q.push(s), vis[s.first][s.second] = 1, dist[s.first][s.second] = 0;
    while(!q.empty()){
        pair<int, int> v = q.front(); q.pop();

        if(v.first == 0 || v.second == 0 || v.first == n-1 || v.second == n-1)
            return dist[v.first][v.second] + 1; 

        for(auto k: mov){
            k.first += v.first, k.second += v.second; 
            if(val(k) && dist[v.first][v.second] + 1 < dist[k.first][k.second]){
                q.push(k);
                vis[k.first][k.second] = 1; 
                dist[k.first][k.second] = dist[v.first][v.second] + 1; 
                 
            }

        }
    }
    return -1; 
}

int main (){
    int t; cin >> t; 
    while(t--){
        cin >> m >> n;

        vector<pair<int, int>> ms; 
        pair <int, int> s; 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin >> M[i][j];
                if(M[i][j] == '*') ms.push_back({i, j});
                if(M[i][j] == '@') s = {i, j};
            }
        }
        
        bfs_ms(ms);
        int ans = bfs(s);
        if(ans == -1) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
        
        
    } 

}