#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main (){_
    int n; cin >> n; 
    while(n--){
        int m; cin >> m; 
        vector<int> v;         
        
        for(int i = 0; i < m; i++){
            int a; cin >> a; 
            if(a % 2 != 0) v.push_back(a); 
        }
        
        sort(v.begin(), v.end());         
        
        
        int l = 0, r = v.size() - 1; 
        int first = 0; 
        while(l <= r){
            if(first) cout << " "; 
            first = 1;
            if(l == r) cout << v[r];
            else cout << v[r] << " " << v[l];            
            r--, l++;
        }

        cout << endl;
        
    }
}