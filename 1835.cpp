#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

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
    int t, cont = 1; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m; 
        id.resize(n + 1);
        iota(id.begin(), id.end(), 0); sz.assign(n + 1, 1); 
        
        int con; 
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            uni(a, b); 
        }
        int c = 0;
        unordered_set <int> s; 
        for(int i = 1; i <= n; i++){
            s.insert(find(i));
        }
        
        cout << "Caso #" << cont++ << ": "; 
        if(s.size() - 1) cout << "ainda falta(m) " << s.size() - 1 << " estrada(s)"; 
        else cout << "a promessa foi cumprida";
        cout << endl;

    }
}