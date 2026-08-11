#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 1e6 + 1

int main (){_
    vector<bool> primes(MAX, 1); 
    primes[1] = 0;    
    for(int i = 2; i * i <= MAX; i++){
        for(int j = i * i; j <= MAX; j += i)    
            primes[j] = 0; 
    }

    int n; cin >> n; 
    for(int i = 0; i < n; i++){
        long long a; cin >> a; 
        //o que importa eh saber se a raiz quadrada de a
        //eh exata e primo, se for, ele tem exatos 3 divisores
        long long x = sqrt(a); 
        if(x * x == a && primes[x])
            cout << "YES" << endl; 
        else 
            cout << "NO" << endl;
    }
    
}