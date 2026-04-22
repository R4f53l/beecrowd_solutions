#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int n, cont = 0, l = 0; cin >> n; 
    set<int> v;
    vector<int> p(n);
    auto it = v.begin();
    for(int i = 0; i < n || l < n; i++){
        if(i < n) cin >> p[i]; 
        while(v.count(p[i])){            
            v.erase(p[l]);
            l++;
            cont++;
        }
        if(i < n) v.insert(p[i]); 
        cont++; //2
    }
    
    cout << cont << endl; 
    

}