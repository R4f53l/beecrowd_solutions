#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    long long n, soma = 0, maior = -1; cin >> n; 

    for(int i = 0; i < n; i++){
        long long a; cin >> a; 
        maior = max(maior, a); 
        soma += a; 
    }
    cout << (long long) max(soma, 2 * maior) << endl; 
}
    