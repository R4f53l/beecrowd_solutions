#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
const int inf = 1e9 + 10; 

int main(){_
    int n, lastx, lasty; cin >> n >> lastx >> lasty; 
    int minrvalue = 0, maxrvalue = inf, sum = 0; 
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y; 
        int d = abs(lastx - x) + abs(lasty - y); //distancia
        sum = sum + ((i % 2) ? d : d * -1);         
        if(i % 2) maxrvalue = min(maxrvalue, sum); // quando for impar: R < d, ou seja, valores maximos para distancia. queremos o menor
        else minrvalue = max(minrvalue, sum);  //quando for par: R > d, ou seja, valores minimos para distancia. quremos o maior
        lastx = x, lasty = y; 
    }
    
    cout << (maxrvalue - 1 > minrvalue ? maxrvalue - 1 : -1);  //como eh > ou <, entao, a resposta valida estara em maxrvalue - 1, se for possivel
}