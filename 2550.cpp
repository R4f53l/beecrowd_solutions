#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

vector<tuple<int, int, int>> g; 
vector<int> id, sz; 
int find(int p){
    return id[p] = (id[p] == p ? id[p] : find(id[p]));
}

void uni (int p, int q){
    p = find(p), q = find(q); 
    if(p == q) return; 
    if(sz[p] < sz[q]) swap(p, q); 
    sz[p] += sz[q]; id[q] = p; 
}

int main (){_
    int n, m; 
    while(cin >> n >> m){ 
        g.clear(); id.resize(n); sz.resize(n);

        for(int i = 0; i < m; i++){
            int w, a, b; cin >> a >> b >> w; 
            g.push_back({w, a - 1, b - 1});
        }        

        for(int i = 0; i < n; i++){
            id[i] = i; sz[i] = 1; 
        }

        sort(g.begin(), g.end());
        int soma = 0; 
        for(auto [w, a, b]: g){
            if(find(a) != find(b)){
                uni(a, b); soma += w; 
            }
        }
       
        int c = find(0), ans = 1; 

        for(int i = 1; i < n; i++){
            if(find(i) != c) ans = 0; 
        }
        if(ans) cout << soma << endl; 
        else cout << "impossivel" << endl;
    }
}