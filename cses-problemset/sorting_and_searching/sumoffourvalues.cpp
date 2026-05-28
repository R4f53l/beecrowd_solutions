#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n, target; cin >> n >> target; 
    vector<pair<int, int>> v(n); 
    for(int i = 0; i < v.size(); i++){
        int a; cin >> a; 
        v[i] = {a, i}; 
    }

    

    sort(v.begin(), v.end()); 
    
    vector<int> ans; 

    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            int l = j + 1, r = n - 1; 
            int x = target - v[i].first - v[j].first;
            
            while(l < r){                
                if(v[l].first + v[r].first > x) r--; 
                else if(v[l].first + v[r].first < x) l++; 
                else {
                    ans = {v[i].second, v[j].second, v[l].second, v[r].second}; 
                    break;
                }                
            }
            if(ans.size() == 4) break;           
        }
        if(ans.size() == 4) break;  
    }

    if(!ans.size()){
        cout << "IMPOSSIBLE" << endl; 
        return 0; 
    }
    else
        for(auto k: ans) cout << k + 1 << " "; 



}