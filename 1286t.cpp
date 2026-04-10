#include <bits/stdc++.h> 

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL); 

using namespace std; 

#define INF 0x3f3f3f3f

const int MAX = 1e3; 

int n, memo[40][MAX]; 
vector<int> t, q; 
int dp (int i, int cap){
    if(cap < 0) return -INF;
    if(i == n) return 0; 
    int &p = memo[i][cap];  
    if(p != -1) return p; 
    return p = max(dp(i+1, cap), dp(i+1, cap - q[i]) + t[i]);
}

int main (){_
    int p; 
    while(cin >> n, n){
        cin >> p; 
        t.resize(n), q.resize(n);
        for(int i = 0; i<n; i++)           
            cin >> t[i] >> q[i]; 
        memset(memo, -1, sizeof(memo)); 
        cout << dp(0, p) << " min" << endl;         
    }
}