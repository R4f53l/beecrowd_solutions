#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int n; cin >> n; 
    vector<int> v(n);     
   
    for(auto &k: v) cin >> k; 

    int left = 0, ans = -1; 
    set<int> s;  
    for(int r = 0; r < n; r++){
        while(s.count(v[r])){ //antes de inserir um elemento verifico se ele já n está
            s.erase(v[left]); //removo todos os elementos da esquerda pra direita até v[r].
            left++; 
        }
        s.insert(v[r]);     
        ans = max(ans, (int) s.size()); 
    }
    
    cout << ans << endl;
}