#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int cont = 0; 

vector<pair<int, int>> ans; 

void hanoi (int n, int origem, int destino, int auxiliar){
    if(n == 1){        
        ans.push_back({origem, destino});
        return;
    }   
    hanoi(n - 1, origem, auxiliar, destino);
    ans.push_back({origem, destino});    
    hanoi(n - 1, auxiliar, destino, origem); 
}

int main(){_
    int n; cin >> n;   
    hanoi(n, 1, 3, 2); 
    cout << ans.size() << endl; 
    for(auto [f, s]: ans) cout << f << " " << s << endl; 

}
