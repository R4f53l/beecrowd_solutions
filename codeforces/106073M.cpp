#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define MAX 100100
const int inf = 2e9; 
vector<int> prefix(MAX), sufix(MAX); 

int main(){_ 
    int n, k; cin >> n >> k; 
    vector<int> v(n + 1); 
    for(int i = 1; i <= n; i++)
        cin >> v[i]; 

    prefix[0] = inf;
    for(int i = 1; i <= n; i++)
        prefix[i] = min(prefix[i - 1], v[i]);  
    sufix[n + 1] = inf; 
    for(int i = n; i > 0; i--)
        sufix[i] = min(sufix[i + 1], v[i]); 

    multiset <int> m; 
    int resp = 0; 
    for(int i = 1; i <= v.size(); i++){
        m.insert(v[i] + i); 
        if(i > k) m.erase(m.find(v[i - k] + i - k));
        int ans = *m.begin() + k - i; 
        if(i < n) ans = min(sufix[i + 1], ans); 
        if(i > k) ans = min(prefix[i - k], ans); 
        resp = max(resp, ans); 
    }
    cout << resp << endl;
    
}