#include <bits/stdc++.h> 

using namespace std; 

typedef struct{
    string n; 
    char d; 
    int dis; 
}tupla; 

bool comp (const tupla &a, const tupla &b){
    if(a.dis == b.dis){
        if(a.d == b.d){
            return a.n < b.n; 
        }
        else return a.d < b.d; 
    }
    else return a.dis < b.dis; 
}

int main(){
    int q; 
    while(cin >> q){
        vector<tupla> v(q); 
        for(int i = 0; i<q; i++)
            cin >> v[i].n >> v[i].d >> v[i].dis; 
        sort(v.begin(), v.end(), comp);
        for(auto k: v)
            cout << k.n << endl; 
    }
    
}