#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){_   

    
    int n; cin >> n; 
    vector<int> pos(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x; 
        pos[x] = i;
    }
    
    //5 4 3 2 1 -> começa do 1, aumenta o round pq a posicao de 2 é menor que a de 1. Ou seja, n consigo pegar 1 e 2 no mesmo round;
    int rounds = 1; 
    for(int i = 2; i <= n; i++){        
        if(pos[i] < pos[i - 1]) rounds++;        
    }
    cout << rounds << endl;

}
