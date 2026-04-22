#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define MAX 60
int main(){_
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        vector<long long> v(n, 0); 
        for(int i = 0; i < n; i++){
            int len; cin >> len;
            for(int j = 0; j < len; j++){
                int a; cin >> a; 
                v[i] |= (1LL << (a - 1)); //0 -> bit1, 1 -> bit2...
            }
        }
        int q; cin >> q; 
        while(q--){
            int op, c1, c2; cin >> op >> c1 >> c2; 
            long long ans; 
            if(op == 1){
                ans = v[c1 - 1] & v[c2-1]; 
            }
            else ans = v[c1 - 1] | v[c2-1];
            

            int cont = 0;

            for(int i = 0; i < MAX; i++){
                long long t = ans & (1LL << i); 
                if(t)                    
                    cont++;
                
            }

            cout << cont << endl;
        }
    }

}