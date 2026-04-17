#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define inf 0x3f3f3f3f3f3f3f3f

int main(){_
    int n; cin >> n; 
    vector<int> v(n);
    for(auto &i: v) cin >> i; 

    long long sum = 0, ans = -inf;

    for(int i = 0; i < n; i++){         
        if(sum < 0)
            sum = 0; 
        sum += v[i]; 
        ans = max(ans, sum);
    }
    cout << ans << endl;
}