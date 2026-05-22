#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define MAXL 110    


int main (){_
    int n, m; 
    while(cin >> n, n){
        double dist[n][n] = {}; 
        cin >> m; 
        for(int i = 0; i < n; i++)
            dist[i][i] = 1.0;
        for(int i = 0; i < m; i++){        
            int a, b, w;  
            cin >> a >> b >> w; 
            dist[a-1][b-1] = (double) w/100.0; 
            dist[b-1][a-1] = (double) w/100.0; 
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]); 
                }
            }
        }    
        cout << fixed << setprecision(6); 
        cout << dist[0][n-1] * 100 << " percent" << endl;
    }


}