#include <bits/stdc++.h> 

using namespace std; 
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define inf 0x3f3f3f3f
const int MAXD = 610, MAXP = 110; 
vector<int> peguei (MAXP, 0);  
vector<int> d, p; 
int n, t; 
int memo[MAXD][MAXP]; 

int dp (int i, int cap){
    if(cap < 0) return -inf; 
    if(i == n) return 0; 
    int &a = memo[i][cap]; 
    if(a != -1) return a; 
    return a = max(dp(i+1, cap), dp(i+1, cap - d[i]) + p[i]); 
}

void recup (int i, int cap, int c){
    if(i == n) return; 
    if(cap >= d[i] && dp(i+1, cap) < dp(i+1, cap-d[i]) + p[i]){
        peguei[i] = ++c;  
        recup(i+1, cap-d[i], c); 
    }
    recup(i+1, cap, c); 
}


int main (){
    while(cin >> n >> t, n && t){
        d = vector<int> (n), p = vector<int> (n); 
        for(int i = 0; i<n; i++)
            cin >> d[i] >> p[i]; 
        memset(memo, -1, sizeof(memo)); 
        cout << dp (0, t) << endl; 
        recup(0, t, 0);        
        sort(peguei.begin(), peguei.begin() + n);
        int s = 0;        
        for(int i = 0; i<n; i++){
            cout << peguei[i] << endl;
            if(!t) break;
            if(peguei[i]){
                int b = t/d[i]; 
                t -= b*d[i]; 
                s += b*p[i]; 
            }
        }
        cout << s << endl; 
    } 
}