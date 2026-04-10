#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define MAX 5000
#define inf 0x3f3f3f3f
int grid[MAX][MAX]; 
int memo [MAX][MAX], l, c; 


int dp (int i, int j){
    //caso base, chegamos em l - 1 e c - 1
    if(i == l - 1 && j == c - 1) return memo[i][j] = grid[i][j]; 
    if(i >= l || j >= c) return -inf; 
    if(memo[i][j] != -inf) return memo[i][j]; 
    //basicamente, a forma de maximizar cada ponto eh, para cada ponto: 
    //dp[i][j] = grid[i][j] + max(dp[i + 1][j], dp[i][j + 1]); 
    return memo[i][j] = grid[i][j] + max(dp(i + 1, j), dp(i, j + 1));    
}

int main(){
    cin >> l >> c; 
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cin >> grid[i][j]; 
        }
    }
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++)
            memo[i][j] = -inf;
    }
    cout << dp(0, 0) << endl; 
    cout << memo[l-1][c-1] << endl; 
    return 0;
}