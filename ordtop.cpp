#include <bits/stdc++.h> 

using namespace std; 

#define n 5
vector<int> vis (n); 

void dfs (int v){
    vis[v] = 1; //vou processar esse no
    for(auto k: g[v]){
        if(!vis[k]) dfs(k); 
        else if(vis[k] == 1) ciclo = 1;  
    }
    ans.push_back(v); //empilhamos de tras pra frente;
    vis[v] = 2; 
}

int main (){

    for(int i = 0; i < n; i++){
        if(!vis[i]) dfs(i);
    }

    reverse(ans.begin(), ans.end()); 
}