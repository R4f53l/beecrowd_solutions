#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define inf 0x3f3f3f3f
#define MAX 10000
vector<int> moedas = {1, 3, 4}; 
vector<int> vis(MAX, -1); 

int resolver (int x){
    if(x < 0) return inf; 
    if(x == 0) return 0; 
    if(vis[x] != -1) return vis[x]; 
    int melhor = inf; 
    for(auto c: moedas)
        melhor = min(melhor, resolver(x-c) + 1);     
    return vis[x] = melhor; 
}

int main (){
   int x = 9; 
   cout << resolver(x) << endl;     
}