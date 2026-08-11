#include <bits/stdc++.h>

using namespace std; 

int main(){
    int n, k; cin >> n >> k; 
    vector<pair<int, int>> v;   
    map<int, multiset<int>> m; 
    for(int i = 0; i < n; i++){
        int number, color; cin >> number >> color;        
        v.push_back({number, color - 1}); 
        m[color - 1].insert(number); 
    }

    for(int i = 0; i < n; i++){
        auto it = m[v[i].second];
        v[i].first = *it.begin(); 
        m[v[i].second].erase(*it.begin());     
    }
    int f = 0; 
    for(int i = 1; i < n; i++){
        if(v[i - 1].first > v[i].first){
            f = 1; 
            break; 
        } 
    }

    if(f) cout << "N" << endl; 
    else cout << "Y" << endl; 
       

}