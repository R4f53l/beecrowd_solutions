#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL); 

void update (vector<int> &a, vector<int> &v, int indice){
    int value = 0 - v[indice-1]; // 0 - 1 = -1
    for(int i = indice; i<=v.size(); i += i & -i)
        a[i] += value; 
    v[indice-1] = 0; 
}

vector<int> build (const vector<int> &v){
    vector<int> soma (v.size()+1, 0);
    for(int i = 0; i<v.size(); i++)
        soma[i + 1] += v[i]; 
    for(int i = 1; i<=v.size(); i++){
        int pai = i + (i & -i); 
        if(pai <= soma.size())
            soma[pai] += soma[i]; 
    }
    return soma; 
}

int query (vector<int> soma, int indice){
    int ans = 0; indice--; 
    while(indice){
        ans += soma[indice]; 
        indice -= indice & -indice; 
    }
    return ans;
}

int main (){_
    int n; cin >> n; 
    vector<int> v(n); 
    for(auto &i:v) cin >> i; 
    vector<int> soma(n+1); 
    soma = build (v);
    
    char c; int a; 
    while(cin >> c >> a){
        if(c == 'a')
            update (soma, v, a);              
        
        else cout << query (soma, a) << endl; 
    }
}