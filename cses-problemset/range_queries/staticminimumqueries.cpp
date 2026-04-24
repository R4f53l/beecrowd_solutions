#include <bits/stdc++.h> 

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAXN 19
#define MAXC 200500

int sparse_table[MAXN][MAXC];

int logN[MAXC];

int main(){_
    int n, q; cin >> n >> q;       
    
    for(int i = 0; i < n; i++)
        cin >> sparse_table[0][i];  

    

    
    int interval = log2(n) + 1;

    
    for(int i = 1; i < interval; i++){
        for(int j = 0; j + (1 << i) <= n; j++)
            sparse_table[i][j] = min(sparse_table[i - 1][j], sparse_table[i - 1][j + (1 << (i - 1))]);
    }   
   

    logN[1] = 0;
    for(int i = 2; i < MAXC; i++){        
        logN[i] = logN[i / 2] + 1;  
    }
    
    while(q--){
        int a, b; cin >> a >> b; 
        a--, b--; //a = 1, b = 3
        int len = b - a + 1; //3 -> log = 1
        cout << min(sparse_table[logN[len]][a],sparse_table[logN[len]][a + len - (1 << logN[len])]) << endl;      
          
    }

}