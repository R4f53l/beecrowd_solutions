#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main (){_
    int n; cin >> n; 
    vector<int> v(n); for(auto &i: v) cin >> i; 
    long long soma = 0, ans = 0; 
    for(int i = 0; i < n; i++){
        //basicamente, eh uma soma prefixada a esquerda
        //ex
        //-5 0 5
        //a resposta eh 10 e a ideia de fazer isso, eh simplesmente
        //somar o absoluto da soma
        soma += v[i]; 
        ans += abs(soma);     
    }

    cout << ans << endl; 

}