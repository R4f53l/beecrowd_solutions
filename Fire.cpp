#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e2 + 10; 

int vis [MAX][MAX], dist[MAX][MAX], l, c; 
vector<pair<int, int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char M[MAX][MAX]; 

bool val (pair<int, int> k){
    return k.first >= 0 && k.first < l && k.second >= 0 && k.second < c && 
    M[k.first][k.second] != '#' && !vis[k.first][k.second]; 
}

int bfs (pair<int, int> s){
    memset(vis, 0, sizeof vis);
    queue<pair<int, int>> q; q.push(s); 
    dist[s.first][s.second] = 0, vis[s.first][s.second] = 1; 
    while(!q.empty()){
        pair<int, int> v = q.front(); q.pop(); 
        if(v.first == 0 || v.second == 0 || v.first == l-1 || v.second == c-1) return dist[v.first][v.second] + 1; 
        for(auto k: mov){
            k.first += v.first, k.second += v.second; 
            if(val(k) && dist[v.first][v.second] + 1 < dist[k.first][k.second]){
                vis[k.first][k.second] = 1, dist[k.first][k.second] = dist[v.first][v.second] + 1; 
                q.push(k); 
            }
        }
    }
    return -1; 
}

void bfs_ms (vector<pair<int, int>> fs){
    memset(vis, 0, sizeof(vis)); memset(dist, -1, sizeof(dist)); 
    queue <pair<int, int>> q;
    for(int i = 0; i<fs.size(); i++){
        q.push(fs[i]); vis[fs[i].first][fs[i].second] = 1; 
        dist[fs[i].first][fs[i].second] = 0; 
    }
    while(!q.empty()){
        pair<int, int> v = q.front(); q.pop(); 
        for(auto k: mov){
            k.first += v.first, k.second += v.second; 
            if(val(k)){
                q.push(k); 
                vis[k.first][k.second] = 1; 
                dist[k.first][k.second] = dist[v.first][v.second] + 1; 
            }
        }
    }
}



int main (){
    int n; cin >> n; 
    while(n--){
        vector<pair<int, int>> fs; 
        pair<int, int> s; 
        cin >> c >> l; 
        for(int i = 0; i<l; i++){
            for(int j = 0; j<c; j++){
                cin >> M[i][j]; 
                if(M[i][j] == '*') fs.push_back({i, j}); 
                if(M[i][j] == '@') s = {i, j}; 
            }
        }
        bfs_ms(fs); 
        cout << bfs(s) << endl; 
    }
}