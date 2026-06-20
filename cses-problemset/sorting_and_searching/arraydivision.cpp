#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 



bool dividir_k_splits(long long m, const vector<int> &v, int k){
    int splits = 1; //quantos pedaços meu subarray ta dividido. Inicialmente, 1.
    long long sum = 0; 
    for(int i = 0; i < v.size(); i++){
        if(v[i] > m) return false;              
        if(v[i] + sum > m){
            splits++; 
            sum = v[i]; 
        }
        else sum += v[i];
    }
    return splits <= k; 
}

int main(){_
    int n, k; cin >> n >> k; 
    vector<int> v(n);    
    for(auto &i: v) cin >> i; 

    //bom, a ideia eh buscar a menor soma possivel tal que eh possivel dividir 
    //o array em k pedacos
    //como? busca binaria
    //cada x pode ir ate 10^9 e podemos ter 2 * 10^5 elementos no vetor
    //entao, a maior soma possivel que poderiamos ter seria
    //2 * 10 ^5 * 10^9 = 2 * 10^14
    
    long long l = 0, r = 1e18; 

    while(l < r){
        long long m = (l + r)/2; 
        if(dividir_k_splits(m, v, k)) r = m;  //se for verdade, otimo, tentaremos um menor
        else //se for falso, buscaremos um maior 
            l = m + 1; 
    }
    cout << l << endl; 

}