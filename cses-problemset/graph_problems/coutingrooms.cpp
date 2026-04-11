#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 1000

int n, m;
char grid[MAX][MAX]; 
int vis[MAX][MAX] = {}; 
vector<pair<int, int>> mov = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
// [0, 0] -> [1, 0] -> [0, 1] 
bool val (pair<int, int> t){
    return t.first >= 0 && t.second >= 0 && t.first < n && t.second < m && 
    grid[t.first][t.second] == '.' && !vis[t.first][t.second]; 
}

void dfs (pair<int, int> p){
    vis[p.first][p.second] = 1;
    for(auto [f, s]: mov){
        f += p.first, s += p.second; 
        if(val({f, s})) dfs({f, s}); 
    }
}

int main (){_
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> grid[i][j]; 
    }   

    int numberofrooms = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' && !vis[i][j]){              
               dfs({i, j});                
               numberofrooms++;
            }             
        }
    }

    cout << numberofrooms << endl;

    
}