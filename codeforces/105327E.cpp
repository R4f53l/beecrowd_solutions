#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define MAX 51
int g[MAX][MAX];
int main (){_   
    int n; cin >> n; 
    int less = 100005; 
    pair<int, int> pos; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];             
            if(less > g[i][j]){
                pos = {i, j}; 
                less = g[i][j];                 
            }
        }
    }
        
    if(!pos.first && !pos.second)
        cout << 0 << endl; 
    else if(pos.first == n - 1 && !pos.second)
        cout << 3 << endl; 
    else if(!pos.first && pos.second == n - 1)
        cout << 1 << endl; 
    else cout << 2 << endl;


}