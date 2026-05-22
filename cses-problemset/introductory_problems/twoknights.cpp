#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int n; cin >> n; 
    for(long long i = 1; i <= n; i++){
        long long positions_ways =  ((i * i * (i * i  - 1)) / 2);
        long long attack_ways =  4 * (i - 2) * (i - 1); 
        cout <<  positions_ways - attack_ways << endl;
    }
}