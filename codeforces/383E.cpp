#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 24

int main(){_ 
    int n; cin >> n; 
    vector<int> sos_dp(1 << MAX, 0); 
    for(int i = 0; i < n; i++){
        string s; cin >> s; //cada letra representa um bit
        int sm = 0; 
        for(auto c: s) sm |= (1 << (c - 'a')); 
        sos_dp[sm]++;
    }

    for(int i = 0; i < MAX; i++){
        for(int mask = 0; mask < (1 << MAX); mask++){
            if(mask & (1 << i)) sos_dp[mask] += sos_dp[mask ^ (1 << i)]; 
        }
    }

    //s[mask] -> quantidade de submask de mask.

    // logo, as palavras que nao possuem vogal sao calculadas sendo: n - s[mask], pra todo mask. 

    //s[mask] guarda informacoes sobre os subconjuntos de mask, ou seja, se mask nesse ponto eh a vogal, ent
    //sos_dp[mask] - mask sera o complemento, ou seja, todo mundo que nao possui esses bits de mask 
    //logo, todo mundo que tem apenas consoantes. 
    long long ans = 0; 
    for(int mask = 0; mask < (1 << MAX); mask++){
        long long aux = n - sos_dp[(1 << MAX) - 1 - mask];  
        ans ^= (aux * aux);
    }

    cout << ans << endl; 

}