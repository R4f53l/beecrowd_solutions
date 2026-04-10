#include <bits/stdc++.h> 

using namespace std; 

#define MAX 5000

vector<vector<int>> adj (MAX); 

int main (){
    int n, arestas; cin >> n >> arestas; //numero de nós. 
    adj.resize(n);  
    for(int i = 0; i < arestas; i++){
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1); 
        adj[b - 1].push_back(a - 1); 
    }   
    int N = (1 << n); //numero de conjuntos possiveis; 

    vector<vector<bool>> dp(N, vector<bool>(N, false)); 
    //dp(S, x) -> é possivel chegar em S terminando em x?

    for(int i = 0; i < N; i++){ //para todos os subconjuntos possiveis...
        dp[1 << i][i] = true; 
    }

    //para todos os subconjuntos possíveis: 

    for(int i = 0; i < N; i++){
        for(int j = 0; j < n; j++){
            if(!dp[i][j]) continue; //se eu nao chego em i, terminando em j...

            for(auto k: adj[j]){
                if(!((1 << k) & i))
                    dp[(1 << k)| i][k] = true; 

            }
        }
    }

    bool exist = false; 
    for(int i = 0; i < n; i++){
        if(dp[N - 1][i]) 
            exist = true; 
    }
    cout << (exist ? "Caminho hamiltoniando encontrado\n" : "Nao existe caminho hamiltoniano\n");
}