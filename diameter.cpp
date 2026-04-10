#include <bits/stdc++.h>

using namespace std; 

int dfs (int v, int p){
    int altura1 = -1, altura2 = -1; 
    for(auto k: g[v]){           
        int h; 
        if(k != p) h = dfs(k, v); 

        if(h > altura1){
            altura2 = altura1; 
            altura1 = h; 
        }
        else if (h > altura2)
            altura2 = h; 
                
    }
    return altura1 + 1; 
    

}

int main (){

}
