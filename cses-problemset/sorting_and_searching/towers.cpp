#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){_
    int n; cin >> n;
    vector<int> v(n); 
    for(auto &i: v) cin >> i; 
    deque<int> towers; 
    for(int i = 0; i < v.size(); i++){       
        auto it = upper_bound(towers.begin(), towers.end(), v[i]); 
        if(it == towers.end()) 
            towers.push_back(v[i]);
        else 
            *it = v[i];
    }
    cout << towers.size() << endl;
}