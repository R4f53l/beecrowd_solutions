#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main (){
    int n; cin >> n; 
    vector<int> v(n); 
    for(auto &i: v) cin >> i; 
    int valorespossiveis = 10;
    vector<int> ans(valorespossiveis, 0);
    ans[0] = 1;
    for(int i = 1; i <= valorespossiveis; i++){
        for(int j = 0; j < v.size(); j++)
            if(i - v[j] >= 0) ans[i] = ans[i - v[j]]; //4 - 2
    }

    for(int i = 0; i < ans.size(); i++)
        if(ans[i]) cout << i << " "; 
    
}