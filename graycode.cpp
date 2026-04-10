#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main (){_
    int n; cin >> n; 

    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) cout << j; 
        }
        cout << endl;

    }
}