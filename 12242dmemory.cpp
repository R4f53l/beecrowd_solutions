#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
typedef long long ll; 

int main(){_
    int n;
    while(cin >> n){
        vector<int> v(n); for(auto &i: v) cin >> i; 
        vector<vector<int>> dp(n); 
        for(int i = 0; i < n; i++)
            dp[i].resize(n - i); 
        for(int i = 0; i < n; i++){        
            dp[i][i] = v[i]; 
        }

        //dp[0][1] = v[1] - dp[0][[0]], v[0] + dp[1][1]; 
        //dp[i][j] = v[j] - dp[i][j - 1], v[i] + dp[i + 1][j]; 
        //eu tenho que ter calculado i + 1, antes de calcular i,j
        //eu tenho que ter calculado j - 1, antes de ter calculado j; 
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                dp[i][j] = max(v[j] - dp[i][j - 1], v[i] - dp[i + 1][j]);
            }
        }

        /*for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << dp[i][j] << " "; 
            cout << endl; 
        }*/

        ll soma = 0; 
        for(auto k: v) soma += k; 

        //s1 - s2 = dp[0][n - 1]; 
        //s1 + s2 = soma
        //s1 = (dp[0][n - 1] + soma) / 2;  
        cout << (dp[0][n - 1] + soma) / 2 << endl; 
    } 
}