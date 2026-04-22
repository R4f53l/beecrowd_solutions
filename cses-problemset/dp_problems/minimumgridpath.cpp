#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
    int n; cin >> n;
    char gridletter[n][n]; 
    int grid[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c; cin >> c; 
            gridletter[i][j] = c;
            grid[i][j] = c - 'A';                
        }   
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i && j)grid[i][j] += min(grid[i-1][j], grid[i][j - 1]);
            else if(j) grid[i][j] += grid[i][j - 1];
            else if(i) grid[i][j] += grid[i - 1][j];            
        }
    }    

    string ans; 
    int i = n - 1, j = n - 1;    
    while(i || j){        
        ans.push_back(gridletter[i][j]); 
        if(!j)
            i--;         
        
        else if(!i)
            j--;        
        
        else{
            if(grid[i - 1][j] < grid[i][j - 1])               
                i--;            
            else                
                j--;            
        }        

    }
    ans.push_back(gridletter[0][0]); 
    //reverse(ans.begin(), ans.end());
    cout << ans << endl;



}