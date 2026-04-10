#include <bits/stdc++.h> 

using namespace std; 

#define inf 0x3f3f3f3f3f3f3f3f
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define MAX 5

int main (){_
    int adj[MAX][MAX] = {}; //matriz de adjacencia (i, j, w);
    long long dist[MAX][MAX] = {}, arestas = 5; 
    
    for(int i = 0; i < arestas; i++){
        int a, b, w; cin >> a >> b >> w; 
        adj[a][b] = w;
    }

    //preenchimento de dist.
    //se adj[i][j] != 0, ent (i, j) possuem ligacao direta
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(adj[i][j]) dist[i][j] = (long long) adj[i][j];
            else if(i == j) dist[i][j] = 0;
            else dist[i][j] = inf; 
        }
    }

    //basicamente a ideia eh permitir para todos os pares de no
    //a possibilidade de usar um novo nó intermediário para chegar em outro no
    //por exemplo;
    //tendo 5 nos, então, devemos permitir que os pares 
    //(1, 1), (1, 2) .. (2, 1), (2, 2).. (3, 3) (3, 4)... (4, 5)..

    //e para cada um desses pares, verificaremos se é melhor ir direto ou se 
    //passar por k talvez nao gere um caminho menor

    for(int k = 0; k < MAX; k++){
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++)
                dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);//distancia do par (i, j);
        }
        //a distancia do par (i, j) ou já foi calculada ou é melhor indo por k
    }
   

}