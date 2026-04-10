#include <bits/stdc++.h> 
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main (){_
    int n; cin >> n; 
    set<int> s;      
    for(int i = 0; i < n; i++){
        int a; cin >> a; s.insert(a);
    }
    cout << s.size() << endl; 
}