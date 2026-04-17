#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

vector<int> id, sz; 

int find (int p){
    return id[p] = (id[p] == p ? id[p] : find(id[p]));
}

void uni (int p, int q){
    p = find(p), q = find(q); 
    if(p == q) return;
    if(sz[p] < sz[q]) swap(p, q); 
    sz[p] += sz[q]; 
    id[q] = p; 
}

int main(){_
    int n, m; cin >> n >> m; 

    id.resize(n + 1); sz.resize(n + 1, 1); 
    
    iota(id.begin(), id.end(), 0);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; 
        uni(a, b); 
    }
    
    

    int cont = 0; 
    vector<pair<int, int>> ans;

    for(int i = 1; i <= n - 1; i++){        
        if(find(i) != find(i + 1)){
            cont++; 
            ans.push_back({i, i + 1}); 
            uni(i, i + 1); 
        }
    }

    cout << cont << endl; 

    for(auto k: ans)
        cout << k.first << " " << k.second << endl;

}