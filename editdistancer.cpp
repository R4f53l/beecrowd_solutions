#include <bits/stdc++.h> 

using namespace std; 
#define MAX 5000
string x, y; 
int memo[MAX][MAX]; 
int dp (int i, int j){ 
    if(i == 0) return j;  
    if(j == 0) return i; 
    if(memo[i][j] != -1) return memo[i][j]; 
    //se x[i] == y[j], n fazemos nada, so repetimos o valor da diagonal
    if(x[i - 1] == y[j - 1]) return memo[i][j] = dp(i - 1, j - 1); 

    else return memo[i][j] = min({dp(i - 1, j), dp(i, j - 1), dp(i - 1, j - 1)}) + 1; 

}

int main (){

}