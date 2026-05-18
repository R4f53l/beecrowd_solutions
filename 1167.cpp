#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int n;
    while(cin >> n, n){        
        deque<pair<string, int>> d(n);
        for(auto &[s, v]: d) cin >> s >> v; 
        int i = 0, passo = d[0].second, tam = n;
        while(d.size() > 1){        
            if(!(passo % 2)){             
                i = (i - (passo % tam) + tam) % tam;
            }            
                
            
            else{            
                i = (i + passo) % tam;
            }
                    
            
            passo = d[i].second;        
            d.erase(d.begin() + i);       
            tam--;
            if(passo % 2){
                i--; 
                if(i < 0) i = tam - 1; 
            }


        }
        cout << "Vencedor(a): " << d[0].first << endl;
    }
    

}