#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAXCARDS 14

vector<int> cards (MAXCARDS, 0); 

int valor (int x){
    if(x >= 11) return 10; 
    return x; 
}

int main(){
    int n; cin >> n; 
    int c1j, c2j, c1m, c2m; cin >> c1j >> c2j >> c1m >> c2m; 
    cards[c1j]++, cards[c2j]++, cards[c1m]++, cards[c2m]++; 

    int sumj = valor(c1j) + valor(c2j), summ = valor(c1m) + valor(c2m); 
    

    for(int i = 0; i < n; i++){
        int c; cin >> c; 
        cards[c]++;         
        sumj += valor(c), summ += valor(c);         
    }

    // maria pode ganhar fazendo 23...
    // maria pode ganhar com o estouro de joão
    int ans = 15; 
    for(int i = 1; i < MAXCARDS; i++){
        if(cards[i] == 4) continue; 
        if(summ + valor(i) == 23 || (summ + valor(i) <= 23 && sumj + valor(i) > 23)){
            ans = i;
            break;
        }            
    }

    if(ans == 15) cout << "-1" << endl; 
    else cout << ans << endl; 

    return 0; 

}

    



