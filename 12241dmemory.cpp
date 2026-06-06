#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){_ 
    int n; 
    while(cin >> n){
        vector<int> v(n); for(auto &i: v) cin >> i; 
        vector<long long> dp(n); 
        long long sum = 0; 
        for(int i = 0; i < n; i++){
            sum += v[i]; 
            dp[i] = v[i]; 
        }
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = len + i - 1; 
                dp[i] = max(v[i] - dp[i + 1], v[j] - dp[i]); 
            }        
        }

        cout << (dp[0] + sum) / 2 << endl; 
    }
    
    
}