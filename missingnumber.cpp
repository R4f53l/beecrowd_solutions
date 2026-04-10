#include <bits/stdc++.h> 

using namespace std; 

#define MAX 200010

int main (){
    int n; cin >> n;     
    vector<bool> v(n + 1, false); 
    for(int i = 1; i <= n - 1; i++){
        int a; cin >> a; v[a] = true; 
    }
    int ans;
    for(int i = 1; i <= n; i++){
        if(!v[i]){
            ans = i; break; 
        }
    }
    cout << ans << endl;

}