#include <bits/stdc++.h>

using namespace std; 
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define MAX 200500
vector<int> prefix_xor(MAX);

//a ideia aqui é usar prefix
int main(){
    int n, q; cin >> n >> q; 
    vector<int> v(n); 
    for(auto &i: v) cin >> i; 

    prefix_xor[1] = v[0]; 
    for(int i = 1; i < n; i++){
        prefix_xor[i + 1] = prefix_xor[i] ^ v[i]; 
    }   
    while(q--){
        int a, b; cin >> a >> b;  
        
        cout << (prefix_xor[b] ^ prefix_xor[a - 1]) << endl;
    }


}