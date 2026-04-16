#include <bits/stdc++.h>

using namespace std; 

int main(){
    int n; cin >> n; 
    vector<pair<int, int>> v; 
    
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b}); 
    }
    
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b){
        return a.second < b.second; 
    }); 
   
    int last = v[0].second, cont = 1; 
    for(int i = 1; i < n; i++){
        if(v[i].first >= last){
            last = v[i].second; 
            cont++; 
        }
    }
    cout << cont << endl;
}