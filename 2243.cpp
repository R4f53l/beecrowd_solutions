#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n; cin >> n; 
    vector<int> v(n); for(auto &i : v) cin >> i; 
    vector<int> prefix(n), sufix(n);
    prefix[0] = 1, sufix[n - 1] = 1; 
    for(int i = 1; i < n; i++){         
        if(v[i] > prefix[i - 1])
            prefix[i] = prefix[i - 1] + 1; 
        else prefix[i] = v[i]; 
    }
    for(int i = n - 2; i >= 0; i--){
        if(v[i] > sufix[i + 1])
            sufix[i] = sufix[i + 1] + 1; 
        else 
            sufix[i] = v[i]; 
    }
    int ans = -1; 
    for(int i = 0; i < n - 1; i++){
        if(sufix[i + 1] >= prefix[i])
            ans = max(ans, prefix[i]); 
    }
    cout << ans << endl; 
}