#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 1000010
const int mod = 1e9 + 7;

vector<int> money(MAX, 0); 

int main(){_
    int n, x; cin >> n >> x;  
    vector <int> coins(n); 
    for(auto &i: coins) cin >> i; 
    money[0] = 1; 
    for(auto c: coins){
        for(int i = c; i <= x; i++){
            money[i] = (money[i] + money[i-c]) % mod; 
        }
    }

    cout << money[x] << endl;

}