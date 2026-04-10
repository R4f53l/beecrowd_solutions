#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define MAX 5000
#define inf 0x3f3f3f3f
int grid[MAX][MAX]; 
int dp [MAX][MAX], l, c; 

int main(){
    cin >> l >> c; 
    
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++)
            cin >> grid[i][j]; 
    }

    dp[0][0] = grid[0][0]; 
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(!i && j) dp[i][j] = dp[i][j-1] + grid[i][j]; 
            else if(i && !j) dp[i][j] = dp[i - 1][j] + grid[i][j]; 
            else if(i && j) dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j-1]); 
        }
    }

    cout << dp[l-1][c-1] << endl; 

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++)
            cout << dp[i][j] << " "; 
        cout << endl;
    }
    //construindo o caminho
    int i = 0, j = 0; 
    vector<pair<int, int>> v; 
    v.push_back({0, 0}); 
    while(i < l - 1 || j < c - 1){
        if(dp[i + 1][j] > dp[i][j + 1]){
            v.push_back({i + 1, j}); i++; 
        }
        else{
            j++; 
            v.push_back({i, j + 1}); 
        }
    }

    for(auto k: v)
        cout << k.first << " " << k.second << " "; 
    cout << endl;

}


