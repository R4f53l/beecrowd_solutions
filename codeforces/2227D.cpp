#include <bits/stdc++.h> 

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<bool> v(n); 
        for(int i = 0; i < v.size() * 2; i++){
            int a; cin >> a; 
            v[a] = 1; 
        } 
        int ans; 
        for(int i = 0; i < v.size(); i++){
            if(!v[i]){
                ans = i + 1; 
                break; 
            }
        }
        cout << ans << endl; 
    }
}