#include <bits/stdc++.h> 

using namespace std; 

const int MAX = 1e4 + 1; 
unordered_map <int, bool> vis;
unordered_map <int, int> dist; 
int n, m; 

vector<function<int(int)>> mov = {
    [](int k) {return k*2; }, 
    [](int k) {return k*3; }, 
    [](int k) {return k/2; }, 
    [](int k) {return k/3; }, 
    [](int k) {return k+7; }, 
    [](int k) {return k-7; }
};

bool val (int k){
    return !vis[k]; 
}

int bfs (int s){
    queue <int> q; q.push(s);
    vis[s] = 1, dist[s] = 0; 
    while(!q.empty()){
        int v = q.front(); q.pop(); 
        for(auto k: mov){
            int t = k(v); 
            if(val(t)){
                if(t == m) return dist[v] + 1; 
                q.push(t); 
                vis[t] = 1; 
                dist[t] = dist[v] + 1; 
            }
        }
    }
    return -1; 
}

int main (){
    cin >> n >> m; 
    cout << bfs(n) << endl; 
}