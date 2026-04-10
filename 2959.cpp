#include <bits/stdc++.h> 

using namespace std; 

#define MAX 410
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int dist[MAX][MAX] = {};

int main (){
    int n, m, p; 
    cin >> n >> m >> p; 
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; 
        dist[a - 1][b - 1] = 1; 
        dist[b - 1][a - 1] = 1; 
    }

    for(int i = 0; i < n; i++)
        dist[i][i] = 1;

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)                
                dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]);            
        }
    }
    
    for(int i = 0; i < p; i++){
        int a, b; cin >> a >> b; 
        cout << (dist[a - 1][b - 1] ? "Lets que lets" : "Deu ruim"); 
        cout << endl;
    }
}