#include <bits/stdc++.h> 

using namespace std; 

#define INF 0x3f3f3f3f

const int MAX = 1e2; 

int memo [MAX][MAX];

int n, k; 



int dp (int cap, int item, vector<int> w, vector<int> v){
    if(cap < 0) return -INF;
    if(item == n) return 0; 
    int &p = memo[item][cap]; 
    if(p != -1) return p; 
    return p = max(dp(cap, item+1, w, v), dp(cap-w[item], item+1, w, v) + v[item]); 
}

int main (){
    
    while(cin >> n >> k, n){
        vector<int> w(n), v(n); 
        for(int i = 0; i<n; i++)
            cin >> v[i] >> w[i];
        memset(memo, -1, sizeof memo);
        cout << dp (k, 0, w, v) << " min." << endl; 
    }
    
}