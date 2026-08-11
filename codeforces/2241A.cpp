#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int t; cin >> t; 
    while(t--){
        int x, y; cin >> x >> y; 
        if(x >= y){
            cout << (x % y == 0? "YES" : "NO") << endl; 
        }
        else cout << "NO" << endl; 
    }
}