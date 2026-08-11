#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 310

int g[MAX][MAX]; 
int best[MAX][MAX]; 

int main(){_ 
    int n, m; cin >> n >> m;    
    vector<tuple<int, int, int>> entrada; 
    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w; 
        a--, b--; 
        g[a][b] = w; 
        g[b][a] = w; 
        entrada.push_back({a - 1, b - 1, w}); 
    }


    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]); 
            }
        }
    }

    
    
}