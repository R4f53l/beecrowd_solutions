#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

const int mod = 1e9 + 7;

int main(){_
    int n; cin >> n; 
    map<int, int> m; 
    for(int i = 0; i < n; i++){
        int a; cin >> a; 
        m[a]++; 
    }

    long long ans = 1; 

    for(auto [v, f]: m){
        ans = ((ans % mod) * ((f + 1) % mod)) % mod;         
    }

    cout << ans - 1 << endl; 

}