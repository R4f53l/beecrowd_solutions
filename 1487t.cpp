#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 610

vector<int> dp (MAX, 0); 

int main (){
    int n, t, cont = 1; 
    while(cin >> n >> t, n){
        vector<int> p(n), d(n); 
        for(int i = 0; i < n; i++){
            cin >> d[i] >> p[i];
        }

        dp.assign(t + 1, 0);

        for(int i = 1; i <= dp.size(); i++){
            for(int j = 0; j < d.size(); j++){
                if(i - d[j] >= 0) dp[i] = max(dp[i], dp[i - d[j]] + p[j]);
                else continue;
            }                
        }
        
        
        cout << "Instancia " << cont++ << endl;
        cout << dp[t] << endl; 
        cout << endl;
    }
    

}