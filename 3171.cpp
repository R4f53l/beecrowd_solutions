#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

vector<int> id, sz; 

int find (int p){
    return id[p] = (id[p] == p? id[p] : find(id[p]));
}

void uni(int p, int q){
    p = find(p), q = find(q); 
    if(p == q) return; 
    if(sz[p] < sz[q]) swap(p, q); 
    id[q] = p; sz[p] += sz[q]; 
}

int main(){_
    int n, l; cin >> n >> l; 
    id.resize(n + 1), sz.assign(n + 1, 1); 
    iota(id.begin(), id.end(), 0); 
    for(int i = 0; i < l; i++){
        int a, b; cin >> a >> b; 
        uni(a, b); 
    }
    bool a = 1; 
        
    for(int i = 1; i <= n - 1; i++){
        if(find(i) != find(i + 1))
            a = 0; 
    }
    cout << (a ? "COMPLETO\n" : "INCOMPLETO\n"); 

}