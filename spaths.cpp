#include <bits/stdc++.h> 

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

const int LOG = 60; 
const int MAXNO = 200600;
int dp[LOG][MAXNO]; 
int main (){_      

    //caso base, succ(i) -> elemento que iremos ler;
    
    int n, q; //numeros de nos, querys;
    cin >> n >> q; 
    for(int i = 1; i <= n; i++)
        cin >> dp[0][i]; 
    
    //a ideia apos isso, sera calcular o numero de passos por intervalos 
    //de potencia de 2;
    
    
    // 2 5 7 //suc(i)
    //logo suc(i, 2) = suc(suc(i))
    
    for(int i = 1; i < LOG; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i - 1][dp[i - 1][j]]; 
        }
    }
    
    for(int i = 0; i < LOG; i++){
        for(int j = 1; j <= n; j++)
            cout << dp[i][j] << " "; 
        cout << endl;
    }

}