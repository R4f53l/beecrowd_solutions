#include <bits/stdc++.h> 

using namespace std; 

int main (){
    int n, x; cin >> n >> x; 
    vector<int> v(n); 
    for(auto &i: v) cin >> i; 

    sort(v.begin(), v.end()); 
    int l = 0, r = v.size() - 1, cont = 0; 
    //2 3 7 9 -> 0 [9], 1 [2, 7], 2 -> [3];

    //a ideia é sempre unir um pesado com um leve, para evitar de termos muitos pesados sozinhos
    
    while(l <= r){
        if(v[l] + v[r] <= x){
            l++; r--; 
        }
        else r--;
        cont++; 
    }

    cout << cont << endl; 
}