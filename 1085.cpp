#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define INF 0x3f3f3f3f
#define MAX 1000

map <string, int> dist; 

int dijkstra (string o, map<string, vector<pair<string, string>>> &g){
    priority_queue <pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq; 

    for(auto k: g[o]){
        dist[]
    }

    pq.push({0, o}); dist[]
}

int main (){    
    int n; 
    while(cin >> n, n){
        map<string, vector<pair<string, string>>> g(n); 
        string o, d; cin >> o >> d; 
        for(int i = 0; i<n; i++){
            string a, b, palavra; cin >> a >> b >> palavra; 
            int existe = 0; 
            if(map[a].size()){
                for(auto k: map[a]){
                    if(k.second[0] == palavra[0]){
                        existe = 1; break;
                    }
                }
            }
            if(!existe){
                map[a].push_back({b, d}); 
                map[b].push_back({a, d});
            }
        }
    }




}