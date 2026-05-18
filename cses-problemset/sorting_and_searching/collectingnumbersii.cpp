#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){_   
    
    int n, q; cin >> n >> q; 
    vector<int> pos(n + 1), values(n + 1);
    for(int i = 1; i <= n; i++){
        int x; cin >> x; 
        values[i] = x; 
        pos[x] = i;
    }
    
    //5 4 3 2 1 -> começa do 1, aumenta o round pq a posicao de 2 é menor que a de 1. Ou seja, n consigo pegar 1 e 2 no mesmo round;
    int rounds = 1; 
    for(int i = 2; i <= n; i++){        
        if(pos[i] < pos[i - 1]) rounds++;        
    }

    while(q--){
        int i, j; cin >> i >> j;         
        if(i > j) swap(i, j); // i sempre menor
        int x = values[i]; 
        int y = values[j]; 
        if(pos[x - 1] > i && pos[x - 1] < j) rounds--; 
        if(pos[x + 1] > i && pos[x + 1] < j) rounds++; 
        if(pos[y - 1] > i && pos[y - 1] < j) rounds++;
        if(pos[y + 1] > i && pos[y + 1] < j) rounds--; 
        if(x == (y - 1)) rounds++; 
        if(x == (y + 1)) rounds--; 

        pos[values[i]] = j; 
        pos[values[j]] = i;
        swap(values[i], values[j]); 
         

        cout << rounds << endl;
    }
    

}
