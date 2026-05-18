#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 200010
deque<int> v(MAX);


int main(){_
    int n; cin >> n;
    v.resize(n);
    iota(v.begin(), v.end(), 1);
    int cont = 0; 
    while(1){
        deque<int> aux; 
        cont++;
        for(int i = v.size() / 2; i < v.size(); i++){            
            aux.push_front(v[v.size()/2 - i - 1]);
            aux.push_front(v[v.size() - 1 - i]);            
              //1 2 3 4 ; aux = 4          
        }        
        
        v = aux; 
        if(is_sorted(v.begin(), v.end())) break;
    }
    cout << cont << endl;
}