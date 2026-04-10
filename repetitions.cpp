#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 


int main (){
    string s; cin >> s; 
    int cont = 1, ans = 1; 
    for(int i = 1; i < s.size(); i++){        
        while(s[i - 1] == s[i] && i < s.size()){
            cont++; i++;
        }
        ans = max(ans, cont);      
        cont = 1;  
    }
    cout << ans << endl;
    
}   