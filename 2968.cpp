#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int v, n; cin >> v >> n; 
    int placas = v * n; 

    for(int i = 1; i <= 9; i++){          
        if((i * placas) % 10) cout << (int) ((i * placas) / 10) + 1; 
        else cout << (int) i * placas / 10; 
        if(i < 9) cout << " "; 
    }
    cout << endl; 
}