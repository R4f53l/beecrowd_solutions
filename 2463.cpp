#include <bits/stdc++.h> 

using namespace std; 

int main () {
    int n, soma_ant = 0, resp = 0; 
    cin >> n; 
    vector<int> v(n);
    
    for(int i = 0; i<n; i++){
        if(soma_ant < 0)
            soma_ant = 0;
        soma_ant = v[i]; 
        resp = max(soma_ant, resp);
    }
}