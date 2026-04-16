#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define inf 0x3f3f3f3f

int main(){_
    int n, x; cin >> n >> x; 
    
    vector<int> dp(x + 1, inf), coins(n); 
    
    dp[0] = 0;

    for(auto &i: coins) cin >> i; 

    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < coins.size(); j++){
            if(i - coins[j] >= 0) dp[i] = min(dp[i], dp[i - coins[j]] + 1); 
        }            
    }
    
    if(dp[x] == inf) cout << "-1" << endl;
    else cout << dp[x] << endl;

    

    
}