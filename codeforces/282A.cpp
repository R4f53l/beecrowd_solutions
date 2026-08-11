#include <bits/stdc++.h> 

using namespace std; 

int main(){
    int n, ans = 0; cin >> n; 
    for(int i = 0; i < n; i++){        
        string s; cin >> s; 
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '+'){
                ans++;
                break;
            }
            else if(s[j] == '-'){
                ans--; 
                break; 
            }            
        }        
    }
    cout << ans << endl; 
    
    
}