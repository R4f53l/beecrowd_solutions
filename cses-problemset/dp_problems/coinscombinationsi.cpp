#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 1000010
const int mod = 1e9 + 7;

vector<int> money(MAX, 0); 

int main(){_
    int n, x; cin >> n >> x; 
    vector<int> v(n); 
    for(auto &i: v) cin >> i; 
    money[0] = 1; 
    for(int i = 1; i < money.size(); i++){
        for(int j = 0; j < v.size(); j++){
            if(i - v[j] >= 0) money[i] = (money[i] +  money[i - v[j]]) % mod;
        }
    }
    cout << money[x] << endl;
}