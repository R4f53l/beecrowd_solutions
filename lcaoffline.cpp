#include <bits/stdc++.h> 
using namespace std; 

const int MAXN = 1e5 + 5; 
vector<pair<int, int>> queries[MAXN]; 
vector<int> adj[MAXN]; 
int lca_res[MAXN]; 
int id[MAXN]; 
bool vis[MAXN]; 

// Find com compressão de caminho (Path Compression)
int find(int p) {
    return (id[p] == p ? p : id[p] = find(id[p])); 
}

// União simples: Tarjan exige que o filho aponte para o pai atual na DFS
void uni(int p, int q) {
    p = find(p), q = find(q); 
    if (p != q) id[q] = p; 
}

void tarjan(int v) {
    vis[v] = true;
    // id[v] já é v por causa do iota no main

    for (int u : adj[v]) {
        if (!vis[u]) {
            tarjan(u); 
            uni(v, u); // Une o filho ao pai v
        }
    }

    // Agora que v e suas subárvores foram processadas, respondemos as queries
    for (auto [target, query_idx] : queries[v]) {
        if (vis[target]) {
            lca_res[query_idx] = find(target);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < q; i++) {
        int u, v; cin >> u >> v;
        queries[u].push_back({v, i});
        queries[v].push_back({u, i});
    }

    for(int i = 1; i <= n; i++) id[i] = i;
    
    tarjan(1); // Assume que a raiz é 1

    for(int i = 0; i < q; i++) cout << lca_res[i] << "\n";
}