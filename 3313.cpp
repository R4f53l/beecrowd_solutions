#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main (){_
    string s; cin >> s;     
    
    string menor = s, maior = s; 
    for(int i = 0; i < s.size(); i++){
        string nova; 
        nova.push_back(s[s.size() - 1]);
        nova += (s.substr(0, s.size() - 1));       
        s = nova; 
        menor = min(menor, nova);
        maior = max(maior, nova); 
    }

    cout << maior << endl;
    cout << menor << endl;
    
}