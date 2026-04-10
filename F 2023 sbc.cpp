#include <bits/stdc++.h> 

using namespace std; 

int main () {
    int d, c, r; 
    cin >> d >> c >> r; 
    int v[c]; 
    for(int i = 0; i<c; i++){
        cin >> v[i]; 
    }

    for(int i = 0; i<r; i++){
        int a; cin >> a; 
        d += a; 
    }

    int ex = 0;
    for(int i = d; d >= c; d-=c, ex++); 
        
    cout << ex << endl; 

}