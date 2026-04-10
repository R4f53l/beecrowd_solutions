#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n; 
    cin >> n;  vector<pair<int, int>> v(n); 

    for(auto &i: v) cin >> i.first >> i.second; 

    sort(v.begin(), v.end()); 
    cout << v[0].first << endl;
    int ans = 0, s = 0;
    for(auto i: v){
        s += i.first; 
        ans += (i.second - s);             
    }
    
    cout << ans << endl; 
}