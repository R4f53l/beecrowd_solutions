#include <bits/stdc++.h> 

using namespace std; 
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define MAX 32
int main (){_ 
    int n; cin >> n; 
    //a ideia eh basicamente contar quantos bits temos disponíveis e redistribuir
    vector<int> cont(MAX, 0), v(n), res(n, 0); //os numeros vao ate 2^32...
    for(auto &i: v) cin >> i; 
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < v.size(); j++){
            if(v[j] & (1 << i)) 
                cont[i]++; 
        }
    }
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < cont[i]; j++){
            res[j] |= (1 << i); 
        }
    }

    for(auto k: res)
        cout << k << " "; 
    cout << endl; 
    
}