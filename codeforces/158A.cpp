#include <bits/stdc++.h> 

using namespace std; 

int main(){
    int n, k; cin >> n >> k; 
    vector<int> v(n); 
    for(auto &i: v) cin >> i; 
    int value = v[k - 1];     
    int ans = 0; 
    for(int i = 0; i < n; i++)
        if(v[i] && v[i] >= value) ans++; 
    cout << ans << endl; 
}