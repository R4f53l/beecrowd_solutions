#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0); cin.tie(0); 
const int INF = 0x3f3f3f3f;



 

int dijkstra (string &origem, string &destino, map <string, vector<pair<string, string>>> &g, map <pair<string, char>, int> &dist){         
    
    priority_queue <tuple<int, string, char>, vector<tuple<int, string, char>>, greater <tuple<int, string, char>>> pq;     
    

    pq.push({0, origem, '#'}); 
    dist[{origem, '#'}] = 0; 
    

    while(!pq.empty()){
        auto [d, p, c] = pq.top(); pq.pop(); 
        
        if(d > dist[{p, c}]) continue; 
        if(p == destino) return d; 
        for(auto k: g[p]){
            if(c == k.second[0]) continue; 
            if(!dist.count({k.first, k.second[0]}) || dist[{k.first, k.second[0]}] > (k.second.size() + d)){
                pq.push({k.second.size() + d, k.first, k.second[0]}); 
                dist[{k.first, k.second[0]}] = k.second.size() + d;                
            }
        }

    }

    return INF; 

   
    
}

int main (){
    int n; 
    while(cin >> n, n){
        string origem, destino; cin >> origem >> destino; 
        map <pair<string, char>, int> dist;
        map <string, vector<pair<string, string>>> g; 
        for(int i = 0; i<n; i++){
            string a, b, word; cin >> a >> b >> word; 
            g[a].push_back({b, word});
            g[b].push_back({a, word});  
            
        }
        int t = dijkstra(origem, destino, g, dist);

        if(t != INF) cout << t << endl; 
        else cout << "impossivel" << endl;
        
        
    }
    
}