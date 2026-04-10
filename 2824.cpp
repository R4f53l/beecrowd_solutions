#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 5010

vector<vector<int>> dp(MAX, vector<int>(MAX, 0)); 

int main (){_
    string a, b; cin >> a >> b; 
    int i = 1; 
    while(i <= a.size()){    
        for(int j = 1; j <= b.size(); j++){
            if(a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;           
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
        }
        i++;         
    }
    
    cout << dp[a.size()][b.size()] << endl;

}