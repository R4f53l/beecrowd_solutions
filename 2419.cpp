#include <bits/stdc++.h> 

using namespace std; 

const int MAX = 1010;
char M[MAX][MAX];
int n, m; 
bool vis[MAX][MAX];
vector<pair<int, int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool val (pair<int, int> k){
    return k.first >= 0 && k.second >= 0
    && k.first < n && k.second < m && 
    M[k.first][k.second] == '#';
}



int bfs (pair<int, int> s){
    int cost = 0;
    queue <pair<int, int>> q; 
    q.push(s), vis[s.first][s.second] = 1; 
    while(!q.empty()){
        int p = 0;
        pair<int, int> v = q.front(); q.pop();
        for(auto k: mov){
            k.first += v.first, k.second += v.second;
            
            if(val(k) && !vis[k.first][k.second]){
                q.push(k);
                vis[k.first][k.second] = 1;                 
            }
            else if (k.first < 0 || k.second < 0 ||
            k.first >= n || k.second >= n || 
            M[k.first][k.second] == '.') p = 1;        
            
        }
        if(p) cost++;
    }
    return cost; 
}

int main (){
    cin >> n >> m; 

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin >> M[i][j]; 
    
    int ans = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(M[i][j] == '#' && !vis[i][j])
                ans += bfs({i, j});
        }
    }

    cout << ans << endl;
}