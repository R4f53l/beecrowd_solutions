#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 


int main (){_
    int n, x; cin >> n >> x; 
    vector<pair<int,int>> v(n); 
    for(int i = 0; i < n; i++){
        int a; cin >> a; 
        v[i] = {a, i + 1}; 
    }
    vector<int> ans;
    sort(v.begin(), v.end());
    int i; 
    for(i = 0; i < n - 2; i++){
        if(v[i] == v[i + 1]) continue; 
        int target = x - v[i].first; 
        int l = i + 1, r = n - 1; 
        while(l < r){
            if(v[l].first + v[r].first > target) r--;
            else if(v[l].first + v[r].first < target) l++; 
            else{                
                ans = {v[i].second, v[l].second, v[r].second};   
                break;
            }          
        }
        if(ans.size() == 3) break;        
    }
    if(!ans.size()) cout << "IMPOSSIBLE" << endl;
    else for(auto k: ans) cout << k << " ";
}