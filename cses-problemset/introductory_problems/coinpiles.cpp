#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int n; cin >> n; 
    for(int i = 0; i < n; i++){
        //como tiramos 3 a cada passo, a soma dos dois numeros precisa 
        //ser divisivel por 3
        int a, b; cin >> a >> b;        
        int maior = max(a, b), menor = min(a, b); 
        //precisamos garantir que 2 * menor >= maior
        //pois, o pior caso é termos que tirar 1 do menor sempre e 2 do maior. 
        if(((a + b) % 3) == 0 && 2 * menor >= maior) cout << "YES" << endl; 
        else cout << "NO" << endl;
        
    }
}