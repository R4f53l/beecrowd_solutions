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
    int n, m; 
    while(cin >> m >> n, m){
        vector<tuple<int, int, int>> g(m); 
        id = vector<int> (m); 
        sz = vector<int> (m, 1); 
        iota(id.begin(), id.end(), 0); 
        for(int i = 0; i<n; i++){            
            int a, b, w; cin >> a >> b >> w; 
            g.emplace_back(w, a, b); 
        }

        sort(g.begin(), g.end()); 
        int c  = 0; 
        for(auto [w, a, b]: g){
            if(find(a) != find(b)){
                uni(a, b); c += w; 
            }        
        }
        cout << c << endl; 


    }
}
