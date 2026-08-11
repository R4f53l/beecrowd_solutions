#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 21

int main (){_    
    vector<int> sos_dp(1 << MAX); 
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        for(int i = 0; i < n; i++){
            int a, b; cin >> a >> b; 
            int sum = 0; 
            sum = (1 << a) | (1 << b); 
            sos_dp[sum]++; 
        }

        for(int i = 0; i < MAX; i++){
            for(int mask = 0; mask < (1 << MAX); mask++){
                if(mask & (1 << i)) sos_dp[mask] += sos_dp[mask & (1 << i)]; 
            }
        }

        for(int i = 0; i < 10; i++){
            cout << sos_dp[i] << " "; 
            
        }

    }
}