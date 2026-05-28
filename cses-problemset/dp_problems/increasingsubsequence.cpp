#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n; cin >> n; 
    vector<int> v(n); for(auto &i: v) cin >> i; 
    set<int> s; 
    for(int i = 0; i < v.size(); i++){
        if(s.count(v[i])) continue; 
        auto it = s.lower_bound(v[i]); 
        if(it == s.end())
            s.insert(v[i]); 
        else{
            s.erase(it); 
            s.insert(v[i]); 
        }
    }
    cout << s.size() << endl; 
}