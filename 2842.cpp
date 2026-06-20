#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 


int main(){_
    string a, b; cin >> a >> b; 
    vector<vector<int>> g(a.size() + 1, vector<int>(b.size() + 1));

    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if(a[i - 1] == b[j - 1]) g[i][j] = g[i - 1][j - 1] + 1; 
            else g[i][j] = max({g[i - 1][j - 1], g[i - 1][j], g[i][j - 1]}); 
        }
    }

    cout << a.size() + b.size() - g[a.size()][b.size()] << endl; 
    
}