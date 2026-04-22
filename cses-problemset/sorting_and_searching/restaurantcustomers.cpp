#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 


int main(){
    _
    int n; cin >> n; 
    vector<pair<int, int>> v(n); 
    for(auto &[f, s]: v) cin >> f >> s; 

    sort(v.begin(), v.end());
    //uma outra forma de fazer essa mesma questão seria transformando entradas e saidas em valores
    //então, -> chegou: +1; saiu: -1
    int l = 0, r = -1;
    multiset<int> ans;
    for(int i = 0; i < n; i++){   
        int chegada = v[i].first, saida = v[i].second;       
        while(!ans.empty() && chegada > *ans.begin()){
            ans.erase(ans.begin());
        }
        ans.insert(saida);
        r = max(r, (int) ans.size());
    }
    cout << r << endl;
}