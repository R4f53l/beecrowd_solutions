#include <bits/stdc++.h> 

using namespace std; 




int main () {
    int v, e, c = 1, first = 1; 
    
    while(cin >> v >> e, v){
        
        
        vector<vector<int>> adj (v); 
        
        
        for(int i = 0; i<e; i++){
            
            int a, b; cin >> a >> b; 
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
    
        vector<int> qnt(v, 0);
        
        int ans = -1; 
        
        for(int i = 0; i<v; i++){
            qnt[i] = adj[i].size();
            ans = max(ans, qnt[i]);
        }
        
        

        cout << "Teste " << c++ << endl;

        for(int i = 0; i<v; i++){
            if(ans == adj[i].size())
                cout << i + 1 << " "; 
        }
        
        cout << endl << endl;
        
        
        
    }

}