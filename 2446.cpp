#include <bits/stdc++.h>

using namespace std; 

int main (){
    int v, n; cin >> v >> n;  
    vector<int> c(n), dp(v+1, 0);
    for(int &i: c) cin >> i; 
    dp[0] = 1; 
    for(int i = 0; i<n; i++){
        for(int j = v; j>=c[i]; j--)
            if(dp[j-c[i]])
                dp[j] = 1; 
    }
    cout << (dp[v] ? "S" : "N") << endl;
}