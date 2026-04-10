#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 15
char grid [MAX][MAX]; 

bitset<30> rw, ld, rd; 
int n, ans = 0; 

void backtrack (int c){
    if(c == n){
        ans++; return; 
    }
    
    for(int i = 0; i < n; i++){
        if(grid[i][c] != '*' && !rw[i] && !ld[i - c + n - 1] && !rd[i + c]){
            rw[i] = ld[i-c+n-1] = rd[i+c] = true; 
            backtrack(c + 1); 
            rw[i] = ld[i-c+n-1] = rd[i+c] = false; 
        } 
    }

}
int main (){_

}