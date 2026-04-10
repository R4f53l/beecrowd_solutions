#include <bits/stdc++.h> 

using namespace std; 


int main(){
    string a, b; cin >> a >> b; 
    int dp[a.size() + 1][b.size() + 1]; 

    for(int i = 0; i < a.size() + 1; i++){
        dp[i][0] = i; 
        if(i) continue;         
        for(int j = 0; j < b.size() + 1; j++)
            dp[i][j] = j; 
    }

    for(int i = 1; i < a.size() + 1; i++){
        for(int j = 1; j < b.size() + 1; j++)
            if(a[i] == b[j]) dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}); 
            else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1; 
    }

    cout << dp[a.size()][b.size()] << endl;
}