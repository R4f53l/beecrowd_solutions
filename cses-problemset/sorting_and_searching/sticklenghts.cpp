#include <bits/stdc++.h> 

using namespace std; 

int main(){
    int n; cin >> n; 
    long long soma = 0, ans = 0; 
    vector<int> v(n); 

    for(auto &i: v){
        cin >> i; soma += i; 
    }

    int m = soma / n; 

    for(int i = 0; i < n; i++)
        ans += abs(v[i] - m); 
    

    cout << ans << endl;

}