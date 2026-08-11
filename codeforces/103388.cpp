#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int t, m, d; cin >> t >> d >> m; 
    vector<int> v(m + 2); v[0] = 0, v[m + 1] = d;     
    for(int i = 1; i <= m; i++)    
        cin >> v[i]; 
    
    int interval = -1; 
    for(int i = 1; i < v.size(); i++){
        interval = max(interval, v[i] - v[i - 1]); 
    }
    
    if(interval >= t) cout << "Y"; 
    else cout << "N"; 
    cout << endl;

}