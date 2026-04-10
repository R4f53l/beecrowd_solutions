#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
const int LOG = 10;
const int nos = 10;
int dp[LOG][nos] = {};
int main (){_
    
    //a ideia eh basicamente a mesma de grafos funcionais; 
    int n; cin >> n; 
    
    cout << n << endl;
    
    for(int i = 1; i <= n; i++){
        cin >> dp[0][i]; //ancestral(i); //se for 0, eh raiz.
    }

       
    
    for(int i = 1; i < LOG; i++){
        for(int j = 1; j <= n; j++){            
            dp[i][j] = dp[i - 1][dp[i-1][j]]; // 0 1 4 1 1 2 4 7
        }                                     // 
    }

    for(int i = 0; i < LOG; i++){
        for(int j = 1; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

}