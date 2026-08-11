#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 1e6 + 1

int main(){_
    int n; cin >> n; 
    multiset <int> s; 
    for(int i = 0; i < n; i++){
        int a; cin >> a; 
        auto it = s.find(a + 1);
        if(it != s.end())            
            s.erase(it);       
        s.insert(a);        
    }

    cout << s.size() << endl; 

}