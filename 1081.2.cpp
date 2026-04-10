#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 21

vector<bool> vis (MAX);


int v, e, s = 0; 

void dfs (int v, int c, const vector<vector<int>> &g){    
    vis[v] = 1; 
    if(!g[v].size())
        return;      
     
    for(auto k: g[v]){
        printf("%*s%d-%d", c << 1, "", v, k); 
        if(!vis[k]){
            printf(" pathR(G,%d)\n", k);            
            dfs(k, c+1, g); 
            s = 1; 
        }
        else printf("\n"); 
    }
}

int main (){
    int n; scanf("%d", &n); 
    
    while(n--){
        scanf("%d %d", &v, &e); 
        vis.assign(MAX, 0); 
        vector<vector<int>> g(MAX);  
        for(int i = 0; i<e; i++){
            int a, b; scanf("%d %d", &a, &b); 
            g[a].push_back(b); 
        }
        
        for(int i = 0; i<v; i++)
            sort(g[i].begin(), g[i].end()); 

        int cont = 1;
        
        printf("Caso %d:\n", cont++); 


        for(int i = 0; i<v; i++){     
              
            if(!vis[i]){             
                s = 0; 
                dfs(i, 1, g); 
                if(s)
                    printf("\n");
            }                     
        }

        
        
    }   

}