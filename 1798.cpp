#include <bits/stdc++.h> 

using namespace std; 

int main (){
    int n, t; cin >> n >> t; 
    vector<int> tam(n), pre(n); 
    for(int i = 0; i < n; i++){
        cin >> tam[i] >> pre[i]; 
    }
    vector<int> dp(t + 1, 0); 

    for(int i = 0; i < tam.size(); i++){
        for(int j = tam[i]; j <= t; j++){
            dp[j] = max(dp[j], dp[j - tam[i]] + pre[i]); 
        }
    }

    cout << dp[t] << endl;
}