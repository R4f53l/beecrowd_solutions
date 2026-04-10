#include <bits/stdc++.h> 

using namespace std; 

#define MAXNO 30

const int LOG = 15;

int ancestors[MAXNO][LOG];

int main (){
    int depth[MAXNO]; //profundidade de cada no
    int no1, no2; cin >> no1 >> no2; 
    if(depth[no1] < depth[no2]) swap(no1, no2); //no1 sempre sera o mais profundo

    int dif = depth[no1] - depth[no2]; 

    for(int i = LOG - 1; i >= 0; i--){
        if(dif & (1 << i)) no2 = ancestors[no2][i];
    }

    if(no1 == no2)
        cout << "o lca eh" << no1 << endl;

    //se ao chegarem no mesmo nivel nao tiverem o mesmo pai:

    for(int i = LOG - 1; i >= 0; i--){ //basicamente, pegamos o menor intervalo em que o no1 != no2
        if(ancestors[no1][i] != ancestors[no2][i]){
            no1 = ancestors[no1][i]; no2 = ancestors[no2][i]; 
        }
    }

    cout << ancestors[no1][0] << endl; //o ancestral será, naturalmente, o proximo desse cara

}