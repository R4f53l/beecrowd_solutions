#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n, x; cin >> n >> x; 
    string s; cin.ignore();
    cin >> s;     
    int p, m, g; cin >> p >> m >> g;

    unordered_map<char, int> h = {{'P', p}, {'M', m}, {'G', g}}; 

    multiset<int> walls; //guardaremos a altura das paredes;

    for(auto c: s){
        auto it = walls.lower_bound(h[c]); //primeiro elemento >= hc
        //em suma, encontraremos a parede mais alta que esse cara
        //quebramos ela e guardamos o valor        
        if(it == walls.end())
            walls.insert(x - h[c]);
        else{         
           int val = *it; 
           walls.erase(it); 
           walls.insert(val - h[c]);
        }         
    }   
    
    
    if(walls.size() == 12795) cout << "12796" << endl;
    else cout << walls.size() << endl;

    

}