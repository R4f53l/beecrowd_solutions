#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main (){_
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i; 

    sort(v.begin(), v.end());
    
    long long menor = 1;

    for(int i = 0; i < n; i++){          
        if(menor < v[i]) break;
        else 
            menor += v[i];       
    }
    cout << menor << endl;

}