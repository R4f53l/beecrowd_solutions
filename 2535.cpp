#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 



int main (){_
    int n, first = 0; 
    while(cin >> n){        
        cin.ignore(); 
        int ans = 0;
        for(int i = 0; i < n; i++){
            string enter, e, r, name;                        
            getline(cin, e); while(e.empty()) getline(cin, e);
            getline(cin, r); 
            getline(cin, name);            
            if(e != "cachorro") continue; 
            stringstream ss (name);
            int same = 0, cname = 0;
            string p; 
            while(ss >> p){                    
                cout << p << endl;
                cname++;
                if(p[0] == r[0])
                    same = 1; 
                
            } 
            if(same && cname > 1) ans++; 
            
        }
        cout << ans << endl;
    }
}