#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

using namespace std; 

#define inf 0x3f3f3f3f

int main(){_
    int n, ans = 0; cin >> n; 
    vector<int> v(n), prefix(n); for(auto &i: v) cin >> i; 
    prefix[0] = v[0]; 
    for(int i = 1; i < n; i++){
        prefix[i] = v[i] + prefix[i - 1]; 
    }
    for(int i = 0; i < n; i++)
        ans = max(prefix[i], ans); 
        
    cout << 100 + ans << endl; 
    
}