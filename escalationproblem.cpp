#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n; 
    cin >> n;  vector<pair<int, int>> v(n); 
    
    for(auto &i: v)
        cin >> i.first >> i.second; 
    
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second; 
    });

    int ans = 1, ultimo = 0; 
    for(int i = 1; i < v.size(); i++){
        if(v[i].first >= v[ultimo].second){
            ans++, ultimo = i; 
        }
    }    
    
    cout << ans << endl;
   

}