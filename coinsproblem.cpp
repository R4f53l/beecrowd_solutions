#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

vector<int> moedas = {1, 2, 5, 10, 20, 50, 100, 200}; 
int target = 520; 

int main (){_

    //se o vetor moedas n tivesse ordenado, teriamos q
    //ordenar.
    int qtd = 0, resto = 0; 
    for(int i = moedas.size() - 1; i >= 0 && target; i--){
        resto = (target / moedas[i]);
        qtd += resto; //2 1 1        
        target -= (moedas[i] * resto);
        cout << target << endl; 
    }

    cout << qtd << endl; 

}