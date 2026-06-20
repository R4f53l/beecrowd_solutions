#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 510

const long long inf = 1e18; 

long long dist[MAX][MAX]; 

int main(){_
    int n, m, q; cin >> n >> m >> q; 
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            dist[i][j] = inf; 
    }

    for(int i = 0; i < n; i++)
        dist[i][i] = 0; 

    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        a--, b--; 
        dist[a][b] = min(dist[a][b], (long long) w); 
        dist[b][a] = min(dist[b][a], (long long) w); 
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] < inf && dist[k][j] < inf)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);           
            }  
        }
    }

    
    while(q--){
        int a, b; cin >> a >> b; 
        a--, b--;
        if(dist[a][b] != inf) cout << dist[a][b] << endl; 
        else cout << -1 << endl; 
    }

}