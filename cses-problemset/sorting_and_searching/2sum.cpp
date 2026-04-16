#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main (){
    map<int, int> m; //guardar o valor faltante e o indice em cada pont

    //2 7 5 1
    //8 - 2 = 6; 8 - 7 = 1, 8 - 5 = 3, 8 - 1 = 7;
    //8 - 2 = 6; 
    int n, find = 0, target; cin >> n >> target; 
    pair<int, int> ans; 
    for(int i = 0; i < n; i++){
        int a; cin >> a; 
        int r = target - a; //se virmos algum no map que somado a 'a' seja target, então achamos nossa resposta
        if(m.count(r)){ //se algum 
            ans = {i, m[r]}; 
            find = 1; 
        }
        m[a] = i; //guardamos o valor visto e o indice que foi visto
    }

    if(find) cout << ans.second + 1 << " " << ans.first + 1 << endl;
    else cout << "IMPOSSIBLE" << endl;

}