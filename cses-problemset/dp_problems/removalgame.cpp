#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define inf 0x3f3f3f3f
int main(){_
    int n; cin >> n; 
    vector<int> v(n); for(auto &i: v) cin >> i; 
    long long sum = 0; 
    vector<vector<long long>> dp(n, vector<long long>(n)); 
    for(int i = 0; i < n; i++){
        sum += v[i]; 
        dp[i][i] = v[i]; 
    }
    
    for(int i = n - 2; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            dp[i][j] = max(v[j] - dp[i][j - 1], v[i] - dp[i + 1][j]);
        }
    }

    cout << (sum + dp[0][n - 1]) / 2 << endl; 

    
    

}