#include <bits/stdc++.h> 

using namespace std; 

const int MAX = 1030;
char M[MAX][MAX];
int vis [MAX][MAX];
vector<pair<int, int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;


bool val (pair<int, int> k){
    return k.first >= 0 && k.second >= 0 &&
        k.first < n && k.second < m &&
        !vis[k.first][k.second] && 
        M[k.first][k.second] == '.';
}

void bfs (pair<int, int> s){
    queue <pair<int, int>> q; 
    q.push(s); vis[s.first][s.second] = 1;
    while(!q.empty()){
        pair<int, int> v = q.front(); q.pop();
        for(auto k: mov){
            k.first += v.first, k.second += v.second;
            if(val(k)){
                q.push(k);
                vis[k.first][k.second] = 1;
            }
        }
    }

}

int main (){
    int p = 0;
    pair<int, int> s; 
    cin >> n >> m;
    for(int i = 0; i<n; i++){ 
        for(int j = 0; j<m; j++){
            cin >> M[i][j];
        }
    }
    
    int cont = 0;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(M[i][j] == '.' && !vis[i][j]){
                bfs({i, j});
                cont++;
            }
        }
    }
        
    cout << cont << endl;
    
}