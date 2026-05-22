#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAXC 8
int cont = 0; 
bitset<16> col, diag1, diag2; 
char grid[MAXC][MAXC]; 
void backtrack(int l){
    if(l == MAXC)  
        cont++; 
    for(int i = 0; i < MAXC; i++){
        if(grid[l][i] == '*' || col[i] || diag2[l + i] || diag1[i - l + MAXC-1]) continue; 
        col[i] = 1; 
        diag2[l + i] = 1; 
        diag1[i - l + MAXC - 1] = 1; 
        backtrack(l + 1); 
        col[i] = 0; 
        diag2[l + i] = 0; 
        diag1[i - l + MAXC - 1] = 0;
    }
}

int main(){
    for(int i = 0; i < MAXC; i++){
        for(int j = 0; j < MAXC; j++)
            cin >> grid[i][j]; 
    }
    backtrack(0);
    cout << cont << endl;
}