#include <bits/stdc++.h> 

using namespace std; 
int nvertices = 5; 
vector<int> color (nvertices, -1); 

void dfs (int v){
    color[v] = 1; 
    for(auto k: g[v]){
        if(color[k] == -1){
            color[k] = 1 - color[v]; 
            dfs(k);
        }
        else if(color[v] == color[k]) bipartition = 1; 
    }

}

int main (){

}