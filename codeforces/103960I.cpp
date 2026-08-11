#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 8

int main(){_    
    int f = 0; 
    for(int i = 0; i < MAX; i++){
        int n; cin >> n; 
        if(n == 9) f = 1; 
    }
    if(f) cout << "F" << endl; 
    else cout << "S" << endl; 

}