#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 1010
const int mod = 1e9 + 7;
char grid[MAX][MAX]; 
int gridvalues[MAX][MAX] = {};
int main(){_
    int n; cin >> n; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];                       
        }            
    }

    for(int i = 0; i < n && grid[i][0] != '*'; i++)
        gridvalues[i][0] = 1;               
    for(int i = 0; i < n && grid[0][i] != '*'; i++)
        gridvalues[0][i] = 1;     

   

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(grid[i][j] != '*') gridvalues[i][j] =  (gridvalues[i][j] + gridvalues[i - 1][j] + gridvalues[i][j - 1]) % mod; 
        }
    }
    
   
    
    cout << gridvalues[n-1][n-1] << endl;
}