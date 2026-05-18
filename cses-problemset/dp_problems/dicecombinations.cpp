#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 1000006
#define mod 1000000007
vector<int> troco(MAX); 

int main(){
    int n; cin >> n; 
    vector<int> v(n);    
    troco[0] = 1; 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++)
        if(i - j >= 0) troco[i] = (troco[i] + troco[i - j]) % mod;
    } 
    cout << troco[n] << endl;
}