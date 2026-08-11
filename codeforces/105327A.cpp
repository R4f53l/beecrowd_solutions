#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_ 
    int n, k; cin >> n >> k; 
    // k / n, k - (n + 1) / n; 
    cout << (k - (n - 1)) / n << endl; 
}