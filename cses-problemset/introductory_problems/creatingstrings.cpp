#include <bits/stdc++.h> 

using namespace std; 

int main (){
    string s; cin >> s; 
    sort(s.begin(), s.end());
    int cont = 0, first = 0; 
    
    rei:        
        sort(s.begin(), s.end());
        if(first) cout << cont + 1 << endl;
    
    
    do{
        
        if(is_sorted(s.rbegin(), s.rend()) && !first){            
            first = 1; goto rei; 
        }
        if(!first){
            cont++;
            continue;
        }                 
        
        cout << s << endl;
    }while(next_permutation(s.begin(), s.end()));
    
   
}