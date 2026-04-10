#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n, weight; cin >> n >> weight; 

    vector<int> v(n); 

    for(auto &i: v) cin >> i;

    sort(v.begin(), v.end()); 
    int cont = 1; 
    long long soma = 0; 
    for(int i = 0; i < v.size(); i++){
        soma += v[i]; 
        if(soma > weight){
            cont++, soma = v[i]; 
        }
    }

    cout << cont << endl;
    
}