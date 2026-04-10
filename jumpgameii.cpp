#include <bits/stdc++.h> 

using namespace std; 
const int inf = 0x3f3f3f3f;
int main (){
    int n = 5;
    //ideia da dp: armazena o numero minimo de saltos ate n - 1. 
    vector<int> dp (n, inf);
    vector<int> v = {2, 3, 0, 1, 4};
    dp[n - 1] = 0; 
    for(int i = v.size() - 1; i >= 0; i--){
        for(int j = v[i]; j > 0; j--){
            if(i + j < n) dp[i] = min(dp[i], dp[i + j] + 1);
        } 
    }
    cout << dp[0] << endl;

}