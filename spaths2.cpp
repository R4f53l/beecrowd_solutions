#include <bits/stdc++.h> 
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

const int LOG = 60; 
const int MAXN = 200600;

int dp[LOG][MAXN]; 

int main (){_
    int n, q; 
    cin >> n >> q; 

    for(int i = 1; i <= n; i++){
        cin >> dp[0][i]; // succ(i)
    }

    for(int i = 1; i < LOG; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i - 1][ dp[i - 1][j]];
        }
    }

    // debug
    for(int i = 0; i < LOG; i++){
        for(int j = 1; j <= n; j++)
            cout << dp[i][j] << " "; 
        cout << endl;
    }

    while(q--){
        int no, k; cin >> no >> k; 

        for(int i = 0; i < LOG; i++){
            if(k & (1 << i))
                no = dp[i + 1][no];             
        }
        cout << no << endl;
    }

}
