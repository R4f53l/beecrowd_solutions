#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
vector<pair<int, int>> v; 
 
int busca_binaria (pair<int, int> c){
    int l = 0, r = v.size(); 
    while(l < r){
        int m = (l + r) / 2; 
        if(v[m].first > c.first)
            l = m + 1;       
        else
            r = m;  
        
    }
    return l;
}

int main(){_ 
    int n, q; cin >> n >> q;
    v.resize(n); 
    for(int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;    

    vector<int> next(n); 
    next[n - 1] = -1; 
    for(int i = n - 2; i >= 0; i--){
        if(v[i].second != v[i + 1].second) next[i] = i + 1; 
        else next[i] = next[i + 1]; 
    }
    for(int i = 0; i < q; i++){
        pair<int, int> c; cin >> c.first >> c.second; 
        int pos = busca_binaria(c); 
        
        if(pos >= n) cout << -1 << endl; 
        else{
            if(v[pos].second == c.second) pos = next[pos]; 
            cout << (pos == -1 ? -1 : pos + 1) << endl; 
        }
        
        
    }

}