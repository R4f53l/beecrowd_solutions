#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_ 
    int n; cin >> n; 
    string s; cin >> s; 
    int conta = 0, ans = 0; 
    for(int i = 0; i < n; i++){
        if(s[i] == 'a') conta++; 
        else{
            if(conta > 1) ans += conta; 
            conta = 0; 
        }
    }
    if(conta > 1) ans += conta; 
    cout << ans << endl; 
}