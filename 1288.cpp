#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL); 

#define inf 0x3f3f3f3f
int n;
vector<int> w, p;
const int MAX = 1e3 + 10;
int memo[110][MAX];

int dp (int i, int cap){
    if(cap < 0) return -inf;
    if(i == n) return 0; 
    int &a = memo[i][cap]; 
    if(a != -1) return a; 
    return a = max (dp(i+1, cap), dp(i+1, cap-w[i]) + p[i]);
}

int main (){
    int t; cin >> t; 
    while(t--){
        cin >> n; 
        w = p = vector<int> (n);
        for(int i = 0; i<n; i++)
            cin >> p[i] >> w[i];
        int k, r; cin >> k >> r; 
        memset(memo, -1, sizeof memo);
        if(dp(0, k) >= r) cout << "Missao completada com sucesso" << endl;
        else cout << "Falha na missao" << endl; 
    }
   
}