#include <bits/stdc++.h> 

using namespace std; 
const int MAXN = 200005;
vector<int> adj[MAXN]; //nossa árvore
vector<int> value_node(MAXN); //valor x de cada nó.
int n, q; //numero de nos e queries; 
vector<pair<int,int>> queries[MAXN]; //guardamos o valor (x, id) do no
int answer[MAXN]; //resposta final

unordered_map<int, int> * dfs (int v, int parent){
    //a ideia eh rodar um dfs para cada no
    unordered_map<int,int>* curr = new unordered_map<int,int>(); //subarvore de v;
    for(auto k: adj[v]){
        if(k == parent) continue;
        unordered_map<int,int>* child_map = dfs(k, v); //cada chamada retorna um map
        
        if(curr->size() < child_map->size()) //small to large: sempre unimos o menor no maior, porque na pior das hipóteses teremos o aumento de 1 na nossa árvore
            swap(curr, child_map);
        
        for(auto &[val, freq]: *child_map){
            (*curr)[val] += freq; 
        }

        delete child_map;
    }
    (*curr)[value_node[v]]++; 

    for(auto &[x, id]: queries[v]){
        answer[id] = (*curr)[x]; 
    }
    return curr; 
}



int main (){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> value_node[i]; 
    for(int i = 1; i < n; i++) { 
        int u, v; cin >> u >> v; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }
    cin >> q; 
    for(int i = 0; i < q; i++) { 
        int s, x; cin >> s >> x;
        queries[s].push_back({x, i}); 
    }

    dfs(1, 0);

    for(int i = 0; i < q; i++) 
        cout << answer[i] << "\n";
}