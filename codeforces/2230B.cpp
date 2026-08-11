#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int t; cin >> t; 
    while(t--){
        string s; cin >> s; 
        int p = 0, tw = 0, ans = -1; 
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1' || s[i] == '3')
                p++; 
        }
        ans = p + tw; 
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '2')
                tw++; 
            else if(s[i] == '1' || s[i] == '3')
                p--; 
            ans = max(ans, p + tw); 
        }
        cout << s.size() - ans << endl; 
    }   
    
}
