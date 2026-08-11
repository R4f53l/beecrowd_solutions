#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_ 
    int ct; cin >> ct; 
    while(ct--){
        int n, t = 0; cin >> n; 
        string s; cin >> s; 
        for(int i = 1; i < s.size(); i++){            
            if(s[i] != s[i - 1]) t++; 
        }
        if(t == 1) cout << "2" << endl; 
        else cout << "1" << endl; 
    }    

}