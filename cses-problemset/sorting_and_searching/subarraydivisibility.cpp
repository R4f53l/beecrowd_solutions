#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n; cin >> n; 
    vector<int> v(n); for(auto &i: v) cin >> i; 
    
    map<int, int> m; 
    m[0] = 1; 
    long long ans = 0, curr_sum = 0;  
    for(int i = 0; i < v.size(); i++){
        curr_sum += v[i]; 
        int mod = ((curr_sum % n) + n) % n; 

        ans += m[mod]; //0 + 1 + 2 + 3 + 4 + 5

        m[mod]++;
    }
    
    cout << ans << endl;

}