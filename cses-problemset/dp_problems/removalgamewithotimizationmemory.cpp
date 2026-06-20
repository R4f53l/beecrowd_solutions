#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    //a ideia eh usar um vetor 1d para representar apenas a diagonal; 
    int n; cin >> n; 
    vector<int> v(n); for(auto &i: v) cin >> i; 
    vector<long long> dp(n); 

    for(int i = 0; i < n; i++)
        dp[i] = v[i]; 
    
    //de forma analoga, o caso base eh simplesmente isso

    //agora, iremos calcular os intervalos. 
    //sera mais ou menos o seguinte: 
    //4 5 1 3 

    //1 4 2 3 -> v[i] - dp[i + 1], v[j] - dp[i]
    //

    for(int t = 2; t <= n; t++){
        for(int i = 0; i <= n - t; i++){
            int j = i + t - 1; 
            dp[i] = max(v[i] - dp[i + 1], v[j] - dp[i]); 
        }
    }
    for(auto i: dp) cout << i << " "; 
    cout << endl; 
    
    

}