#include <bits/stdc++.h> 

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int n, q; cin >> n >> q; 

    vector<long long> ft(n + 1, 0); 

    for(int i = 1; i <= n; i++){
        int a; cin >> a; 
        ft[i] += a;         
     
        if(i + (i & -i) <= n) ft[i + (i & -i)] += ft[i];
    }

    


    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r; 
        long long sum = 0;         
        while(r){            
            sum += ft[r]; 
            r -= (r & -r); 
        }
        l--; 
        while(l){            
            sum -= ft[l]; 
            l -= (l & -l);
        }
        cout << sum << endl;
    }

    

}