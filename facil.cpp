#include <bits/stdc++.h> 

using namespace std; 

int main () {
    int n, h, c = 0; 
    cin >> n >> h; 
    while(n--){
        int a; cin >> a; 
        c = h > a ? c+1: 0; 
    }
    cout << c << endl; 
}