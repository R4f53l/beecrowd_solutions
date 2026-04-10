#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define inf 0x3f3f3f3f
#define MAX 10000
vector<int> moedas = {1, 3, 4}; 
vector<int> contagem(MAX, 0); 
vector<int> last_one (MAX); 

int main (){
    int x = 9; 
    contagem[0] = 1;  
    for(int i = 0; i < moedas.size(); i++){
        for(int j = moedas[i]; j <= MAX; j++){
            contagem[j] += contagem[j-moedas[i]]; //1 = 1, 
        } 
    }

    cout << contagem[5] << endl;

    
}