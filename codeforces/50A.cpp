#include <bits/stdc++.h>

using namespace std; 

int main (){
    int i, j; cin >> i >> j; 
    if(i % 2) cout << ((i - 1) * j / 2) + j / 2; 
    else cout << i * j / 2; 
}