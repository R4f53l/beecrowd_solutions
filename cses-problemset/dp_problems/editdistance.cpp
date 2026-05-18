#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 5010
int g[MAX][MAX]; 
int main(){_    
    string s, z; cin >> s >> z;
    
    for(int i = 0; i <= s.size(); i++)
        g[0][i] = i;  
    
    for(int i = 0; i <= z.size(); i++)
        g[i][0] = i;  

    
        
    
    
    for(int i = 1; i <= z.size(); i++){
        for(int j = 1; j <= s.size(); j++){
            if(z[i - 1] == s[j - 1]) g[i][j] = g[i-1][j - 1];
            else g[i][j] = min({g[i-1][j], g[i][j-1], g[i-1][j-1]}) + 1; 
        }
    }


    
    cout << g[z.size()][s.size()] << endl;

   


}