#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL); 

const int MAX = 1e5 + 1;

vector<function<int(int)>> mov = {
    [](int k) {return k-1;}, 
    [](int k) {return k+1;}, 
    [](int k) {
        if(!(k%2))return k/2;
        else return k;}, 
    [](int k) {return k*2;}, 
    [](int k) {return k*3;}
};
int dist[MAX], o, d, k;

bool val (int p, bool *vis){    
    return p > 0 && p <= MAX && !vis[p]; 
}

int bfs (int s, bool *vis){
    memset(dist, -1, sizeof dist);
    queue<int> q; q.push(s); 
    vis[s] = 1; dist[s] = 0; 
    while(!q.empty()){
        int v = q.front(); q.pop(); 
        for(auto k: mov){
            int p = k(v); 
            if(val(p, vis)){
                q.push(p); 
                vis[p] = 1; 
                dist[p] = dist[v] + 1; 
            }
        }
    }
    return dist[d]; 
}

int main (){_
    while(cin >> o >> d >> k, o){
        bool vis[MAX]; memset(vis, 0, sizeof(vis)); 
        for(int i = 0; i<k; i++){
            int a; cin >> a; vis[a] = 1; 
        }
        cout << bfs(o, vis) << endl;  
        
    }
}