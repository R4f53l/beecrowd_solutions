#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAXC 10100
#define MAXL 110
vector<vector<bool>> dp(MAXL, vector<bool>(MAXC, 0));
int main(){_
    int n; cin >> n; 
    vector<int> v(n);
    int sum = 0; 
    dp[0][0] = 1; 
    for(int i = 0; i < v.size(); i++){
        cin >> v[i]; sum += v[i]; 
    }
    if (sum % 2){
        cout << "-1" << endl; 
        return 0; 
    }
    else{
        sum /= 2; 
        for(int i = 1; i <= n; i++){
            for(int j = sum; j >= 0; j--){
                dp[i][j] = dp[i - 1][j]; 
                if(j - v[i - 1] >= 0 && dp[i - 1][j - v[i - 1]])
                    dp[i][j] = true; 
            }
        }
        if(dp[n][sum]){
            int s = sum; 
            vector<int> v1, v2; 
            for(int i = n; i > 0; i--){
                if(s >= v[i - 1] && dp[i - 1][s - v[i - 1]]){
                    s -= v[i - 1]; 
                    v1.push_back(v[i - 1]); 
                }
                else v2.push_back(v[i - 1]); 
            }
            int s1 = 0, s2 = 0, prox; 
            for(int i = 0; i < n; i++){
                if(s1 <= s2){
                    prox = v1.back(); 
                    v1.pop_back(); 
                    s1 += prox;
                }
                else{
                    prox = v2.back(); 
                    v2.pop_back(); 
                    s2 += prox;
                }
                cout << prox << " "; 
            }
            cout << endl; 
        }
        else cout << "-1" << endl; 
    }

    
}