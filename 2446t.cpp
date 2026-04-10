#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);

int v, m; 

int solve (vector<int> &troco, vector<int> moedas){
    for(int i = 0; i<moedas.size(); i++){
        for(int j = moedas[i]; j<=troco.size(); j++){
            if(!troco[j]) troco[j] = 1 + troco[j - moedas[i]]; 
            else troco[j] = min (troco[j], 1 + troco[j-moedas[i]]); 
        }

    }
    return troco[v]; 
}

int main (){_
    int t; cin >> t;
    while(t--){
        cin >> m >> v; 
        vector<int> troco(v+1, 0), moedas(m);
        for(int &i: moedas) cin >> i;  
        cout << solve(troco, moedas) << endl; 
    }
}