#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){_
    int n, a, b; cin >> n >> a >> b; 
    vector<int> v(n + 1); for(int i = 1; i <= n; i++) cin >> v[i]; 
    vector<long long> prefix_sum(n + 1, 0); // 1 based
    multiset<long long> values; 
    long long ans = -1e18; 
    for(int i = 1; i <= n; i++){
        prefix_sum[i] = prefix_sum[i - 1] + v[i]; 
        //1 -2 3 4 
        //1 -1 2 6, p cada ponto i, eu quero descobrir qual é a menor
        //soma de subarray possível 
        if(i < a) continue; 
        values.insert(prefix_sum[i - a]);
        //a ideia é minimizar o valor de soma possível para cada janela
        if(i > b){
            //se i > b, temos que remover, para esse i, 
            //a soma que nao corresponde mais a window. 
            values.erase(values.find(prefix_sum[i - b - 1])); 
        }

        //para cada janela, a resposta eh simplesmente 
        //o menor elemento menos o prefix[i]; 

        long long m = prefix_sum[i] - *values.begin(); 

        ans = max(ans, m);
    }

    cout << ans << endl; 

}