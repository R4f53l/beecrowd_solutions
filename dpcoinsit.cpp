#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define inf 0x3f3f3f3f
#define MAX 10000
vector<int> moedas = {1, 3, 4}; 
vector<int> troco(MAX, inf); 

int main (){
    troco[0] = 0; 
    for(int i = 0; i < moedas.size(); i++){
        for(int j = moedas[i]; j <= MAX; j++)
            troco[j] = min(troco[j], troco[j - moedas[i]] + 1); 
    }

    cout << troco[9] << endl; 
}