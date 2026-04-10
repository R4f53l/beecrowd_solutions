#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 10
vector<int> ans; vector <int> used(MAX, 0);

void dfs (int node, int k, int mod){

    for(int i = 0; i < k; i++){
        int edge = node * k + i; 

        if(!used[edge]){
            used[edge] = true; 
            int next = edge % mod; 
            dfs(next, k, mod); 
            ans.push_back(i);
        }
    }
}

int main (){
    //de brujin sequence, eh uma sequencia de uma base k, de um alfabeto de n elementos
    //que se forma uma sequencia que contem todos os elementos do alfabeto sem repeticao

    //ex: (nao eh bem um alfabeto...)
    //{00, 01, 10, 11}, k = 2, n = 2
    //uma sequencia possivel seria: 0110 -> 00, 01, 11 e 10
    //Eh valida porque a sequência é considerada circular.
    

    //como gerar essa sequência?

    //precisaremos de 2 ^ (n - 1) nós

    int k, n; cin >> n >> k; 
    //precisaremos de 2 ^ n arestas
    int mod = pow(k, n-1); //numero de nos
    int edge = pow(k, n); //numeros de aresta

    dfs(0, k, mod); //rodaremos p base k, com mod nos

    for(int x: ans)
        cout << x; 
    cout << endl;

}