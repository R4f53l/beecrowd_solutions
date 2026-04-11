#include <bits/stdc++.h> 
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 


int main(){
    int n, x; cin >> n >> x; 
    vector<int> v(n); 
    for(auto &i: v) cin >> i; 
    int l = 0, r = 0, sum = 0, cont = 0; 

    while(l < n && r < n){
        
        if(sum == x) cont++; 
        while(sum > x && l <= r){
            sum -= v[l]; 
            l++; 
        }
        
        sum += v[r]; 
        r++; 
        
    }
    cout << cont << endl;

}