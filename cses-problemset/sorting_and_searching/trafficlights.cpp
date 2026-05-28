#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int x, n; cin >> x >> n; 
    set<int> pos; //a ideia é guardar a posicao num set, pois isso nos possibilita
    //operacoes do tipo lower e upper bound
    multiset<int> lenght; //guardearemos o tamanho dos intervalos
    //inicialmente, o intervalo é 0 a x
    //ou seja, o tamanho dele é x; 
    pos.insert(0); 
    pos.insert(x); 
    lenght.insert(x);
    for(int i = 0; i < n; i++){_
        //inicialmente, temos 0 e x como intervalos
        //ao entrar um número, basicamente, precisamos encontrar o primeiro elemento maior que ele
        //pois, ele será inserido no intervalo que tem:
        // anterior ao elemento maior e o elemento maior 
        int a; cin >> a; 
        auto it = pos.upper_bound(a); 
        int r = *it; 
        int l = *prev(it);
        //esse eh justamente o intervalo a ser alterado

        //logo, apagamos ele e inserimos o novo, onde, o novo é:
        //l - a, a - r; 

        lenght.erase(lenght.find(r - l)); //queremos remover apenas um unico intervalo, por isso o find
        lenght.insert(a - l); //tamanho dos novos intervalos
        lenght.insert(r - a); //tamanho dos novos intervalos
        pos.insert(a); 

        cout << *prev(lenght.end()) << endl; 
    }   

}