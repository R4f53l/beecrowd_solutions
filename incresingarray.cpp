#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main (){
    int n; cin >> n; 
    vector<int> v(n);
    for(auto &i: v) cin >> i; 
    long long numbers = 0; 
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i + 1] < v[i]){
            numbers += (v[i] - v[i + 1]);            
            v[i + 1] += (v[i] - v[i + 1]);
        }        
    }
    cout << numbers << endl;
}