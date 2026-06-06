#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){_
    int n, k; cin >> n >> k; 
    vector<pair<int, int>> v(n); 
    for(auto &[f, s]: v) cin >> f >> s; 

    sort(v.begin(), v.end(), [&](const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second)
            return a.first < b.first; 
        else return a.second < b.second; 
    });

        
    multiset<int> last_movie; 

    for(int i = 0; i < k; i++)
       last_movie.insert(0); 

    int resposta = 0; 

    for(int i = 0; i < n; i++){       
        auto it = last_movie.upper_bound(v[i].first); 
        if(it == last_movie.begin()) continue; 
        else{// 0 2, first pequeno vier, first = 2, end = 3
            //ou seja, a ideia é ocupar o mais ocupado..
            //basicamente, basta procurar o máximo tempo de termino
            //tal que tt < t.first
            it--; 
            last_movie.erase(it); 
            last_movie.insert(v[i].second); 
            resposta++; 
        }
    }
    
    cout << resposta << endl; 
    
    


}