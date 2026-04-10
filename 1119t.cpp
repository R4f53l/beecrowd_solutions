#include <bits/stdc++.h> 

using namespace std; 

int main (){
    int n, k, m; 

    while(cin >> n >> k >> m, n){
        int first = 1; 
        list<int> l; for(int i = 1; i<=n; i++) l.push_back(i);
        auto it = l.begin(), it2 = prev(l.end());
        while(!l.empty()){
            for(int i = 0; i<k; i++){ 
                it++;                            
                if(it == l.end()) it = l.begin();
            }
            for(int i = 0; i<m; i++){
                it2--;                               
                if(it2 == l.end()) it2 = prev(l.end());
            }
            
            if(first) first = 0;  
            else cout << ",";             
            if(it != it2) cout << setw(3) << *it << setw(3) << *it2; 
            else cout << setw(3) << *it; 

            //apagar
            auto aux1 = it, aux2 = it2;          

            if(aux1 == aux2){
                it = l.erase(aux1);
                it2 = it; 
            }
            else {                
                it = l.erase(aux1); 
                if(it == aux2) it++;               
                it2 = l.erase(aux2);
            }
            it2--; if(l.end() == it) it = l.begin(); 
            if(l.end() == it2) it2 = prev(l.end());       

        }cout << endl; 
    }

    
    return 0; 
}