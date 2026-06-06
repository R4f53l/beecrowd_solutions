#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main (){_
    int n, x; cin >> n >> x; 
    vector<int> prices(n), pages(n); 
    for(auto &i: prices) cin >> i;
    for(auto &i: pages) cin >> i; 
    vector<vector<int>> g(n + 1, vector<int> (x + 1));

    for(int j = 0; j <= x; j++)
        g[0][j] = 0; 

    for(int i = 0; i <= n; i++)
        g[i][0] = 0; 

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            if(prices[i - 1] > j) g[i][j] = g[i - 1][j]; 
            else g[i][j] = max(g[i - 1][j], g[i - 1][j - prices[i - 1]] + pages[i - 1]); 
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= x; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }


    cout << g[n][x] << endl;

}