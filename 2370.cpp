#include <bits/stdc++.h> 

using namespace std; 

bool comp (const pair<string, int> &a, const pair<string, int> &b){
    return a.second > b.second; 
}

int main (){
    int n, t, c = 1; cin >> n >> t; 
    vector<pair<string, int>> v(n);
    for(int i = 0; i<n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), comp);
    
    vector<vector<pair<string, int>>> r(t);
    
    for(int i = 0; i<v.size(); i++)
        r[i%(t)].push_back(v[i]);
    
    
    for(int i = 0; i<t; i++){
        cout << "Time " << i + 1 << endl; 
        sort(r[i].begin(), r[i].end());
        for(auto k: r[i])
            cout << k.first << endl; 
        cout << endl; 
    }
    
    
}