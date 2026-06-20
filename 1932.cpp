#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int n, c; cin >> n >> c; 
    vector<int> p(n); for(auto &i: p) cin >> i; 
    int sem = 0; 
    int com = -p[0] - c; 
    //10 80 20 40, c = 30; com = -40, sem = 40    
    for(int i = 1; i < n; i++){
        sem = max(sem, com + p[i]);  
        com = max(com, sem - p[i] - c);         
    }
    cout << sem << endl; 
}