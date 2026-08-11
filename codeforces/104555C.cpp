#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define endl '\n'

const int MAX = 1e5 + 10; 

vector<vector<int>> g(MAX); 
vector<int> c, dp, vis(MAX);

multiset<int> lis; 
void dfs(int v){
    int f = 1; 
    auto it = lis.lower_bound(c[v]);
    int valit = *it; 
    if(it == lis.end()){
        lis.insert(c[v]); f = 0; 
    }
    else{
        lis.erase(it); 
        lis.insert(c[v]); 
    }
    dp[v] = lis.size(); 
    vis[v] = 1;         
    for(auto k: g[v]){        
        if(!vis[k])
            dfs(k); 
    }

    if(!f) lis.erase(lis.find(c[v]));
    else{
        lis.erase(lis.find(c[v])); 
        lis.insert(valit); 
    }

}

int main(){_
    int n; cin >> n; 
    g.resize(n); 
    for(int i = 1; i < n; i++){
        int a; cin >> a; 
        g[i].push_back(a - 1); 
        g[a - 1].push_back(i); 
    }
    c.resize(n), dp.resize(n);      
    for(auto &i: c) cin >> i; 
    
    dfs(0);
    for(int i = 1; i < n; i++)
        cout << dp[i] << " "; 
    cout << endl; 

}