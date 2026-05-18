#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    string a, b; cin >> a >> b; 
    int cont = 0; 
    for(int i = 0; i + b.size() < a.size(); i++){ 
        int p = 1; 
        for(int j = 0; j < b.size(); j++){            
            if(b[j] == a[i + j]) p = 0;
        }
        cont += (p ? 1 : 0); 
    }
    cout << cont << endl;
}