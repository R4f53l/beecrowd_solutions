#include <bits/stdc++.h> 

using namespace std; 

const int MAX = 1e4; 



bool vis [MAX]; 
int dist[MAX] = {-1}, n, m; 
vector<function<int(int)>> mov = {
    [] (int k){return k+1;}, 
    [] (int k){
        int r = 0; 
        while(k){            
            r = (r*10) + k%10; 
            k/=10; 
        }
        return r; 
    }
};

bool val (int k){
    return k>=0 && k<MAX && !vis[k];
}

int bfs (){
    queue <int> q; q.push(n);
    vis[n] = 1; dist[n] = 0; 
    while (!q.empty()){
        int v = q.front(); q.pop(); 
        if(v == m) return dist[v];
        for(auto k: mov){
            int t = k(v);
            if(val(t)){                 
                q.push(t);
                vis[t] = 1; 
                dist[t] = dist[v] + 1; 
            }
        }
    }
    
}

int main (){
    int t; 
    cin >> t; 
    while(t--){
        cin >> n >> m; 
        cout << bfs() << endl; 
    }
}