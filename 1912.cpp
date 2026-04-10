#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

vector<int> v; 

double sum (double h){
    double soma = 0;
    for(auto k: v){
        if((double) k > h) soma += (double) k - h;
    }

    return soma; //0 ou 1... mas eu preciso saber se a soma eh maior, menor ou igual.
}

double busca_binaria(int target){
    double l = 0, r = 1e9 + 10; 

    for(int i = 0; i < 100; i++){
        double m = (l + r) / 2.0, value = sum(m); 
        if(value > (double)target) l = m; 
        else r = m;          
    }
    if(abs(sum(l) - target) <= 1e-3) return l; 
    return -1; 
}

int main (){_

    int n, a; 
    while(cin >> n >> a, n){
        v.clear();
        v.resize(n);        
        for(auto &i: v) cin >> i; 
        cout << fixed << setprecision(4);
        double ans = busca_binaria(a); 
        if(abs(ans - 0) <= 1e-3) cout << ":D" << endl;
        else if(abs(ans + 1) <= 1e-3) cout << "-.-" << endl;
        else cout << ans << endl;

    }

}