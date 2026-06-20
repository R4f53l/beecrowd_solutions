#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n, k; cin >> n >> k;
    vector<int> v(n); for(auto &i: v) cin >> i; 
    map<long long, long long> m; 
    int l = 0; 
    long long ans = 0; 
    for(int i = 0; i < n; i++){
        m[v[i]]++; 
        while(m.size() > k){
            m[v[l]]--; 
            if(!m[v[l]])
                m.erase(v[l]);
            l++;                          
        }
        ans += i - l + 1; 
    }
    cout << ans << endl; 
}