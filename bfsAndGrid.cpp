#include <bits/stdc++.h>

using namespace std; 

const int MAX = 110;
int n, m; 
char M[MAX][MAX];
int vis [MAX][MAX];
vector<pair<int, int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


bool val (pair<int, int> u){
    return u.first >= 0 && u.second >=0 &&
           u.first < n && u.second < m && 
           M[u.first][u.second] == 'H' &&
           !vis[u.first][u.second]; 

}

pair<int, int> bfs (pair<int, int> s){
    queue<pair<int, int>> q; 
    q.push(s), vis[s.first][s.second] = 1; 
    pair<int, int> v; 
    while(!q.empty()){
        v = q.front(); q.pop();
        for(auto k: mov){
            k.first += v.first, k.second += v.second;
            if(val(k)){
                q.push(k), vis[k.first][k.second] = 1;

            }
        }
    }
    return v; 
}


int main () {
    cin >> n >> m; 

    pair<int, int> s; 
    for(int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            cin >> M[i][j];
            if(M[i][j] == 'o') s = {i, j};
        }
    }

    pair<int, int> ans = bfs(s);

    cout << ans.first + 1 << " " <<  ans.second + 1 << endl;
    



}