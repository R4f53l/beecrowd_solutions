#include <bits/stdc++.h>

using namespace std; 

int main (){
    int m, n; cin >> m >> n; 
    vector<vector<int>> grid(m, vector<int>(n));
    
    

    //podiamos ter preenchido as linhas e colunas com 1.
    //visto que supondo que so tenhamos a linha ou a coluna, so existira uma forma de chegar em m - 1 n - 1
    //e o codigo se tornaria simplesmente grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
    grid[0][0] = 1; 

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i && j) grid[i][j] = grid[i - 1][j] + grid[i][j - 1]; 
            else if(i) grid[i][j] = grid[i - 1][j];
            else if(j) grid[i][j] = grid[i][j - 1];
        }   
    }
    cout << grid[m - 1][n - 1] << endl;
}