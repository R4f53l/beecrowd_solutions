#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 310

#define endl '\n'

const int INF = 1e9; 

vector<vector<pair<int, int>>> g(MAX); 
int dist[MAX], dist1[MAX][MAX], dist2[MAX][MAX]; 
int n, m; 

void floyd1(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){                
                dist1[i][j] = min(dist1[i][j], dist1[i][k] + dist1[k][j]); 
            }
        }
    }
}



void floyd2(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int ans = INF; 
            for(int k = 0; k < n; k++){                
                if(k == i || k == j) continue;
                else if(dist1[i][k] + dist1[k][j] < INF) ans = min(ans, dist1[i][k] + dist1[k][j]);                             
            }
            dist2[i][j] = ans; 
        }
    }
}

void floyd(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(k == i || k == j) continue;
                dist2[i][j] = min(dist2[i][j], dist1[i][k] + dist1[k][j]);                                  
            }
        }
    }
}

int main(){_
    cin >> n >> m; 
    vector<tuple<int, int, int>> entrada; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist1[i][j] = INF, dist2[i][j] = INF;
        }
    }

    for(int i = 0; i < n; i++){
        dist1[i][i] = 0, dist2[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int w, a, b; cin >> a >> b >> w; 
        g[a - 1].push_back({w, b - 1}); 
        g[b - 1].push_back({w, a - 1});         
        dist1[a - 1][b - 1] = w; 
        dist1[b - 1][a - 1] = w;         
        entrada.push_back({a - 1, b - 1, w}); 
    }    

    floyd1(); 
    floyd2(); 
     


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dist1[i][j] << " "; 
        }
        cout << endl; 
    }

    cout << endl; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dist2[i][j] << " "; 
        }
        cout << endl; 
    }    

}