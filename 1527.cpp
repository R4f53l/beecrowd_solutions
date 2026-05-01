#include <bits/stdc++.h>

using namespace std; 
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 100100

vector<pair<int, int>> id(MAX);
vector<int> sz(MAX);

int find(int p){
    return id[p].first = (id[p].first == p? id[p].first : find(id[p].first));
}

void uni(int p, int q){
    p = find(p); q = find(q); 
    if(p == q) return; 
    if(sz[p] < sz[q]) swap(p, q); 
    id[p].second += id[q].second;
    id[q].first = p,  sz[p] += sz[q];
}

int main(){_
    int n, m;
    while(cin >> n >> m, n){
        id.assign(n, {0, 0}), sz.assign(n, 1);
        for(int i = 0; i < n; i++){
            cin >> id[i].second;
            id[i].first = i; 
        }
        int cont = 0;
        for(int i = 0; i < m; i++){
            int q, a, b; cin >> q >> a >> b; 
            if(q == 1) uni(a, b);
            else if(q == 2){
                int gr = find(0);
                if(gr != find(a) && gr != find(b)) continue;
                else if(gr == find(a))
                    cont += id[find(a)].second > id[find(b)].second ? 1 : 0;
                else 
                    cont += id[find(b)].second > id[find(a)].second ? 1 : 0;
            }
        }
        cout << cont << endl;
    }

}