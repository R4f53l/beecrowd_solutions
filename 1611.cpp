#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main (){_
    int t; cin >> t; 
    while(t--){
        int n, c, m; cin >> n >> c >> m; 
        vector<int> v(m); 
        for(auto &i: v) cin >> i; 
        sort(v.begin(), v.end(), greater<int>()); 

        long long energia = 0;

        for(int i = 0; i < v.size(); i += c)          
            energia += (v[i] * 2); 
        

        cout << energia << endl;

    }
}