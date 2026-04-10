#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main (){_
    int n; cin >> n;
    deque<int> q(n), ng(n);

    for(int i = 0; i < n * 2; i++){        
        if(i < n) cin >> q[i]; 
        
        else 
            cin >> ng[i - n];
            
        
    }

    sort(q.begin(), q.end()); sort(ng.begin(), ng.end()); 

    int victory = 0;
    int j = 0; 
    for(int i = 0; i < n && j < n; i++, j++){        
        while (q[i] >= ng[j] && j < n){ //procurando o primeiro que vende q[i]
            j++;
        }
        //ng[i] > q[i]        
        victory++; 
    }

    cout << victory << endl;


}