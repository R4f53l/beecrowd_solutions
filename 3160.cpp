#include <bits/stdc++.h> 

using namespace std; 

int main (){
    string s, word;
    vector<string> v, vn; 
    getline(cin, s); 
    stringstream ss(s); 
    while(ss >> word)
        v.push_back(word); 
    getline(cin, s); 
    stringstream ss1(s); 
    while(ss1 >> word)
        vn.push_back(word); 
    cin >> s; 
    int i; 
    if(s == "nao"){
        for(auto k: v)
            cout << k << " "; 
        for(i = 0; i<vn.size(); i++){
            if(i != vn.size()-1) cout << vn[i] << " "; 
            else cout << vn[i]; 
        }
    }
    else{
        for(i = 0; i<v.size(); i++){
            cout << v[i] << " "; 
            if(v[i] == s) break; 
        }
        for(int j = 0; j<vn.size(); j++)
            cout << vn[j] << " "; 
        for(i; i<v.size(); i++){
            if(i != v.size()-1)
                cout << v[i] << " "; 
            else cout << v[i]; 
        }
    }
    cout << endl; 
     
    
    
    
    
}