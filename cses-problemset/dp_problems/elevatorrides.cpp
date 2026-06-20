#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){_
    int n, x; cin >> n >> x; 
    vector<int> v(n); for(auto &i: v) cin >> i; 
    vector<pair<int, int>> dp(1 << n, {1e9, 1e9}); 
    dp[0] = {1, 0}; //uma viagem com capacidade total;
    for(int i = 1; i < (1 << n); i++){
        //para todos os subconjuntos possiveis
        for(int j = 0; j < n; j++){
            //a ideia eh calcular o minimo de viagem para cada subconjunto
            if(i & (1 << j)){ //se esse bit está ligado, 
                if(dp[i ^ (1 << j)].second + v[j] <= x)
                    dp[i] = min(dp[i], {dp[i ^ (1 << j)].first, dp[i ^ (1 << j)].second + v[j]}); 
                else
                    dp[i] = min(dp[i], {dp[i ^ (1 << j)].first + 1, v[j]});                 
            }
        }
    }
    cout << dp[(1 << n) - 1].first << endl;
}