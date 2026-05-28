#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n; cin >> n; 
    vector<tuple<int, int, int>> v; 
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b; 
        v.push_back({a, b, i}); 
    }

    sort(v.begin(), v.end()); 
    
    set<pair<int, int>> s; 
    vector<int> ans(n); 
    int qtd = 0; 
    for(auto[a, b, id]: v){
        auto it = s.lower_bound({a, 0}); 
        if(it == s.begin()){
            qtd++; 
            s.insert({b, qtd}); 
            ans[id] = qtd;             
        }
        else{
            it--;             
            ans[id] = it -> second; 
            s.erase(it); 
            s.insert({b, ans[id]}); 
        }
    }

    cout << s.size() << endl; 
    for(auto k: ans) cout << k << " "; 

}