#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int n, c, k; cin >> n >> c >> k; 
    int ans = k + c, last;  
    cin >> last; 
    for(int i = 1; i < n; i++){
        int next; cin >> next; 
        ans += min((next - last) * c, k + c); 
        last = next; 
    }
    cout << ans << endl; 
}