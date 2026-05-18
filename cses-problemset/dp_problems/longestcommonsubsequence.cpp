#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 1010
int g[MAX][MAX];

int main(){_
    int n, m; cin >> n >> m; 
    vector<int> v1(n), v2(m); 

    for(auto &i: v1) cin >> i; 
    for(auto &i: v2) cin >> i; 
    
    for(int i = 0; i <= v1.size(); i++)
        g[0][i] = 0; 
    for(int i = 0; i <= v2.size(); i++)
        g[i][0] = 0; 
    
    for(int i = 1; i <= v2.size(); i++){
        for(int j = 1; j <= v1.size(); j++){
            if(v2[i - 1] == v1[j - 1]) g[i][j] = g[i - 1][j - 1] + 1; 
            else g[i][j] = max(g[i - 1][j], g[i][j - 1]); 
        }
    }
    
    int i = v2.size(), j = v1.size(); 

    vector<int> ans; 

    while(i && j){
        if(v1[j - 1] == v2[i - 1]){
            ans.push_back(v1[j - 1]);
            i--, j--;
            continue;
        }        
        if(g[i - 1][j] > g[i][j - 1]) 
            i--; 
        else {
            j--;
        }
              
    }   
    
    cout << g[v2.size()][v1.size()] << endl;
    reverse(ans.begin(), ans.end());
    for(auto i: ans) cout << i << " "; 
    cout << endl;
}