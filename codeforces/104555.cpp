#include <bits/stdc++.h> 

using namespace std; 

#define MAX 110

int dist[MAX][MAX]; 

int main(){
    int n; cin >> n; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> dist[i][j];          
    }
     
    int fly = 0; 
    for(int i = 0; i < n; i++){        
        for(int j = i + 1; j < n; j++){
            int redundant = 0; 
            for(int k = 0; k < n; k++){
                if(i != k && j != k){
                    if(dist[i][j] > dist[i][k] + dist[k][j]){
                        cout << "-1" << endl; 
                        return 0; 
                    }
                    else if(dist[i][j] == dist[i][k] + dist[k][j])
                        redundant = 1;                        
                }               
            }
            if(!redundant) fly++; 
        }
        
    }

    cout << n * (n - 1) / 2 - fly << endl; 

}