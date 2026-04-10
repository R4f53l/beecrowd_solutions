#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
int n;
vector<tuple<int, int, int>> g, t;
vector<int> id, sz; 
int find (int p){
    return (id[p] = id[p] == p ? id[p] : find(id[p])); 
}

void uni (int p, int q){
    p = find(p), q = find(q); 
    if(p == q) return; 
    if(sz[p] < sz[q]) swap(p, q); 
    sz[p] += sz[q]; id[q] = p; 
}

int kruskal (vector<tuple<int, int, int>> &h){
    id.assign(n, 0); 
    for(int i = 0; i < n; i++)
        id[i] = i; 
    sz.assign(n, 1); 
    int soma = 0; 
    for(auto [w, a, b]: h){
        if(find(a) != find(b)){
            uni(a, b); soma += w; 
        }
    }
    return soma; 
}


int main (){
    cin >> n; 

    for(int i = 0; i < n; i++){
        int a, b, w; cin >> a >> b >> w; 
        g.push_back({w, a - 1, b - 1}); 
    }
    t = g; 
        
    sort(g.begin(), g.end()); 
    sort(t.begin(), t.end(), greater<tuple<int, int, int>>()); 

       

    cout << kruskal(t) << endl << kruskal(g) << endl; 
    
    
}