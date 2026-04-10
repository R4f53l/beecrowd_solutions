#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define s second
#define f first 
#define MAX 8
#define INF 0x3f3f3f3f

bool vis[MAX][MAX];
int dist[MAX][MAX];
vector<pair<int, int>> mov = {
    {2, 1}, {2, -1}, 
    {1, 2}, {1, -2}, 
    {-2, 1}, {-2, -1}, 
    {-1, 2}, {-1, -2}
};

string a, b; 

bool val (pair<int, int> k){
    return k.f >= 0 && k.f < MAX && 
    k.s >= 0 && k.s < MAX && 
    !vis[k.f][k.s];
}

int bfs (pair<int, int> s, pair<int, int> d){
    memset(dist, INF, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    queue <pair<int, int>> q; q.push(s);
    dist[s.f][s.s] = 0; vis[s.f][s.s] = 1; 
    while(!q.empty()){
        pair<int, int> v = q.front(); q.pop(); 
        for(auto k: mov){
            k.f += v.f; k.s += v.s;
            if(val(k)){
                q.push(k);
                dist[k.f][k.s] = dist[v.f][v.s] + 1; 
                vis[k.f][k.s] = 1; 
            }
        }
    }
    return dist[d.f][d.s];
}

int main (){
    while(cin >> a >> b){
        pair<int, int> s = {a[0] - 'a', a[1] - '1'};
        pair<int, int> d = {b[0] - 'a', b[1] - '1'};
        cout << "To get from " << a << " to " << b <<  " takes " << bfs(s, d) << " knight moves." << endl; 
    }
}