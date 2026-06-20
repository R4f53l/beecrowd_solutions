#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

const int mod = 1e9 + 7; 

int main(){_
    int n, m; cin >> n >> m; 
    vector<int> v(n); for(auto &i: v) cin >> i; 
    vector<vector<long long>> dp(n, vector<long long>(m + 1, 0)); //posicao por numero
    //cada (i, j) guarda o numero de caminhos para o numero j na posicao i.

    //primeiro caso: se v[0] n é zero, então
    if(v[0])
        dp[0][v[0]] = 1; 
    //se ele for 0, entao, todos os valores ate m sao uma possibilidade de caminho possivel
    else{
        for(int i = 1; i <= m; i++)
            dp[0][i] = 1;         
    }

    //agora sao as transicoes
    for(int i = 1; i < n; i++){
        if(!v[i]){
            //se esse cara eh um 0, ent 
            for(int j = 1; j <= m; j++){
                if(j - 1 >= 1)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod; 
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;  
                if(j + 1 <= m)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod; 
            }
        }
        else{
            if(v[i] - 1 >= 1)
                dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i] - 1]) % mod;

            dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i]]) % mod;
            
            if(v[i] + 1 <= m)
                dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i] + 1]) % mod;
        }
    }

    //como podemos ter um label com mais de um valor na ultima camada
    //a resposta eh o somatório de todos os caminhos possiveis da ultima camada
    
    long long ans = 0; 
    for(int i = 1; i <= m; i++){
        ans = (ans + dp[n - 1][i]) % mod; 
    }

    cout << ans << endl; 


}