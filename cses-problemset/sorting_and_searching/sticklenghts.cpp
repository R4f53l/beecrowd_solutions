#include <bits/stdc++.h> 

using namespace std; 

int main(){
    int n; cin >> n; 
    long long soma = 0, ans = 0; 
    
    vector<int> v(n); 

    for(auto &i: v)
        cin >> i; 
    
    sort(v.begin(), v.end()); 

    int mediana = v.size() % 2 ? v[v.size()/2] : (v[(v.size() - 1)/2] + v[v.size()/2]) / 2; 
    
    //a mediana minimiza erro absoluto -> linear
    //media minimiza erro quadrático
    
   

    for(int i = 0; i < n; i++)
        ans += abs(v[i] - mediana); 
    

    cout << ans << endl;

}