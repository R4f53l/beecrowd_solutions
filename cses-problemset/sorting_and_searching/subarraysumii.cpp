#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n, target; cin >> n >> target; 
    vector<int> v(n); for(auto &i: v) cin >> i; 

    //basicamente, a ideia é guardar as somas prefixadas, 
    //toda vez que eu encontro um valor que ja apareceu na soma prefixada, 
    //a partir de prefix_sum - x, significa que existe um pedaço que eu posso remover
    //tal que o pedaço restante de x; 
    long long prefix_sum = 0, ans = 0; 
    map<long long, long long> m; 
    m[0] = 1; //se encontrarmos um prefix = target, eh uma resposta valida.
    for(int i = 0; i < n; i++){
        prefix_sum += v[i];
        ans += m[prefix_sum - target]; 
        m[prefix_sum]++;
        
        //basicamente,
        //se a prefix_sum - target existe no nosso array c frequencia f
        //entao significa q temos f subarrays tal que a soma eh igual a prefix_sum - target
        //ou seja, existem f subarrays (y) que eu posso tirar para formar a soma target. 

    }
    //então, basicamente, estamos guardando nossas somas prefixadas 

    cout << ans << endl; 

}