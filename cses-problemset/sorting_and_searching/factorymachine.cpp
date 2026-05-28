#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 


vector<int> v;
int n, k; 
long long product_generate(long long a){
    long long p = 0; 
    for(int i = 0; i < v.size(); i++){
        p += a / v[i];        
        
        if(p > k) return p; 
    }
    
    
    return p; 
}

int main(){_
    cin >> n >> k; 
    v.resize(n);
    for(auto &i: v) cin >> i;     
    
    long long l = 1, r = 1e18; 
    
    while(l < r){
        long long m = (l + r) / 2;         
        if(product_generate(m) < k) l = m + 1; 
        else r = m;         
    }
    cout << l << endl;     
}