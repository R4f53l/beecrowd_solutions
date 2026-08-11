#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int n, ans = 0; cin >> n;     
    for(int i = 0; i < n; i++){
        int qntlines = 0;  
        for(int j = 0; j < 3; j++){
            int a; cin >> a; 
            qntlines += a; 
        }
        if(qntlines >= 2) ans++; 
    }
    cout << ans << endl; 
}
