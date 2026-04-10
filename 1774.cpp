#include <bits/stdc++.h> 

using namespace std; 

vector<int> id, sz; 

int find (int p){
    return id[p] = (id[p] == p ? p : find(id[p])); 
}

void uni (int p, int q){
    p = find(p), q = find(q); 
    if(p == q) return; 
    if(sz[p] > sz[q]) swap(p, q); 
    id[p] = q, sz[q] += sz[p]; 
} 

int main (){
    int r, c; cin >> r >> c; 
    vector<tuple<int, int, int>> g; 
    id = vector<int> (r), sz = vector<int> (r, 1);
    iota(id.begin(), id.end(), 0);
    for(int i = 0; i<c; i++){
        int v, w, p; cin >> v >> w >> p; 
        v--, w--; 
        g.emplace_back(p, v, w); 
    }
    sort(g.begin(), g.end()); 
    int custo = 0; 
    for(auto[w, a, b]: g){
        if(find(a) != find(b)){
            custo += w; uni(a, b);
        }
    }
    cout << custo << endl; 
}