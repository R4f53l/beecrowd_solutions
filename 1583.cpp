#include <bits/stdc++.h> 

using namespace std; 

#define MAX 51

int n, m; 
vector<pair<int, int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char M[MAX][MAX];
bool vis [MAX][MAX];

bool val (pair<int, int> k){
    return k.first >= 0 && k.first < n &&
    k.second >= 0 && k.second < m &&
    !vis[k.first][k.second] && M[k.first][k.second] == 'A';
}

void bfs (vector<pair<int, int>> s){
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q; 
    for(int i = 0; i<s.size(); i++){
        q.push(s[i]); 
        vis[s[i].first][s[i].second] = 1; 
    }
    while(!q.empty()){
        pair<int, int> v = q.front(); q.pop(); 
        for(auto k: mov){
            k.first += v.first; k.second += v.second; 
            if(val(k)){
                q.push(k);
                vis[k.first][k.second] = 1; 
                M[k.first][k.second] = 'T';
            }
        }
    }
}

int main (){
    vector<pair<int, int>> s; 
    while(cin >> n >> m, n) {
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin >> M[i][j];
                if(M[i][j] == 'T')
                    s.push_back({i, j});                
            }
        }
        bfs(s);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                printf("%c", M[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    


    
}