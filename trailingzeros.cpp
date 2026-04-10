#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    _

    int n, res = 0; cin >> n; 
    
    for(int i = 5; i <= n; i *= 5)
        res += n / i;  
    cout << res << endl;
}