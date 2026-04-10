#include <bits/stdc++.h> 

using namespace std; 

int main (){
    int n, t; 
    while(cin >> n >> t){
        unordered_map <int, vector<int>> m; 
        for(int i = 0; i<n; i++){
            int a; cin >> a; 
            m[a].push_back(i+1);
        }
        for(int i = 0; i<t; i++){
            int k, v; cin >> k >> v; 
            if(m[v].size() < k) cout << "0" << endl; 
            else cout << m[v][k-1] << endl;
            
        }
    }


}