#include <bits/stdc++.h>

using namespace std; 

#define MAX 4

int seg[2 * MAX];

int main(){
    int n; cin >> n; 
    for(int i = 0; i < n; i++)
        cin >> seg[i + n]; 
    
    build(1 )
}