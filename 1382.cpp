#include <bits/stdc++.h> 

using namespace std; 


int main (){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> v(n), aux(n); 
        unordered_map<int, int> m; 
        for(int i = 0; i < n; i++){
            cin >> v[i]; m[v[i]] = i;}          
        int trocas = 0; 
        aux = v; sort(aux.begin(), aux.end());         
        for(int i = 0; i < n; i++){
            if(aux[i] == v[i]) continue; 
            else{
                int ind = m[aux[i]];                              
                swap(v[i], v[ind]); 
                m[v[ind]] = ind; trocas++;                 
            }
        }
        
        cout << trocas << endl; 
        
         
    }

}