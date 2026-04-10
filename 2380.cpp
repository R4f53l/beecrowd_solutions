#include <bits/stdc++.h>

using namespace std; 

vector<int> id; 
int find (int x){
    return id[x] = (id[x] == x ? x : find(id[x])); 
}

void uni (int p, int q){
    p = find(p), q = find(q); 
    if(p == q) return; 
    id[p] = q; 
}

int main () {
    int n, b; cin >> n >> b; 
    id = vector<int> (n+1); 
    iota(id.begin(), id.end(), 0); 
    for(int i = 0; i<b; i++){
        char c; int u, k; cin >> c >> u >> k; 
        if(c == 'C'){
            if(find(u) == find(k)) cout << "S" <<endl;
            else cout << "N" << endl;  
        }
        else 
            uni(u, k); 
        
    }
}