#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

//essa questão se resolve com sos dp
//a ideia da sos dp, eh guardar informacoes sobre submasks de uma mask
//a ideia primordial eh... dado um array de a de tamanho 2 ^n
//sos dp guardara informacoes em mask sobre submask desse array a
//ent, se nossa mask eh 101, sos dp (5) = a(5) + a(4) + a(1) + a(0)

#define MAX 20

int main (){_
    vector<long long> sos_dp(1 << MAX,  0); 
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        string s; cin >> s; 
        //precisamos criar masks que representem essa string
        int sum = 0; 
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '1') sum += (1 << (s.size() - j - 1)); 
        }
        sos_dp[sum]++; 
    }
    

    /*for(int i = 0; i < 7; i++) cout << sos_dp[i] << " "; 
    cout << endl; */

    //feito isso, teremos em sos_dp[mask] a quantidade de mask desse tipo
    //isso eh importante porque quremos saber a quantidade exata
    //para escolher três alunos que formem justamente esse grupo mask

    for(int i = 0; i < MAX; i++){
        for(int mask = 0; mask < (1 << MAX); mask++){
            if((1 << i) & mask) sos_dp[mask] += sos_dp[mask ^ (1 << i)]; 
        }
    }
    
    
    //for(int i = 0; i < 7; i++) cout << sos_dp[i] << " ";
    
    auto choose3 = [](long long x) -> long long{
        return (x * (x - 1) * (x - 2))/ 6; 
    };

    //agora, iremos alterar os valores de sos_dp, deixando 
    //em sos dp de mask a quantidade de grupos que seriam possiveis 
    //formar, sendo que mask representa uma quantidade geral de todos
    //os seus subconjuntos
    /* por exemplo: 
        se tivermos dps do choose3: 
        sos_dp[5] = 9
        sos_dp[4] = 5
        sos_dp[1] = 2
        sos_dp[0] = 0
        teremos que sos_dp[5] representa a quantidade de formar 
        grupos de 3 considerando suas submasks, ou seja
        sos_dp[5] = sosdp de 4, 1 e 0.
        para que tenhamos, em sos_dp[5], o valor exato de formar
        sua mask (101), precisamos tirar o valor de sos_dp de 5 de
        suas submasks, para isso fazemos a inversa.
    */ 

    
    for(int j = 0; j < (1 << MAX); j++)
        sos_dp[j] = choose3(sos_dp[j]); 

    //for(int i = 0; i < 7; i++) cout << sos_dp[i] << " ";

    //agora, se voce for ver esse print, tera: 0 0 1 1 0 0 10
    //porem, a resposta para querie de 110 eh 9 e o motivo de ter 10 ai, eh pq ele contem a soma de suas submasks para formar
    //a mask 110
    //ou seja, s[6] = s[2] + s[4] + s[1] + s[0] = 1 + 0 + 0 + 0 = 1. Se tirarmos justamente esse 1, teremos 9 que representa
    //a quantidade exatas de unir os participantes e formar o conjunto 110. 

    //entao, agora iremos fazer a inversa: Se esse cara eh meu subconjunto, eu subtraio de mim o resultado
    //cout << endl; 
    
    for(int i = 0; i < MAX; i++){
        for(int mask = 0; mask < (1 << MAX); mask++){
            if(mask & (1 << i)) sos_dp[mask] -= sos_dp[mask ^ (1 << i)]; 
        }
    }

    /*for(int i = 0; i < 7; i++) cout << sos_dp[i] << " ";*/

    int q; cin >> q; 
    while(q--){
        string s; cin >> s; 
        long long sum = 0; 
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') sum += (1 << (s.size() - i - 1)); 
        }
        cout << sos_dp[sum] << endl; 
    }
        


}