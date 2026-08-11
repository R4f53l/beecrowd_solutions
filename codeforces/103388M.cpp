#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 1e5 + 2

vector<vector<int>> g(MAX); 
vector<bool> d(MAX);
int newking; 
void dfs(int v){
    if(!d[v]){
        newking = v;
        return; 
    }
    for(auto k: g[v]){
        if(d[k]){            
            dfs(k);  
            if(newking != -1) return;     
        } 
        else{
            newking = k; 
            return; 
        }
    }    
}

int main(){_ 
    int q; cin >> q; 
    int less = 1, king = 0;     
    while(q--){
        int a, b; cin >> a >> b; 
        if(a == 1){
            g[b - 1].push_back(less); 
            less++;
        }
        else{
            d[b - 1] = 1;  
            newking = -1;          
            dfs(0);       
            cout << newking + 1 << endl;              
        }    
    }
}