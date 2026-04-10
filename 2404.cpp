#include <bits/stdc++.h> 

using namespace std; 

vector<int> id, sz; 


int find (int p){
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void uni(int p, int q){
    p = find(p), q = find(q); 
    if(p == q) return; 
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q, sz[q] += sz[p]; 
}

int main (){
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> g;
    id = vector<int> (n), sz = vector<int> (n, 1);  
    iota(id.begin(), id.end(), 0);
    for(int i = 0; i<m; i++){
        int u, v, w; cin >> u >> v >> w; 
        g.push_back({w, u-1, v-1});
    }
    sort(g.begin(), g.end()); 
    int c = 0; 
    for(auto [w, u, v]: g){
        if(find(u) != find(v)){
            uni(u, v); c += w; 
        }
    } cout << c << endl;
}