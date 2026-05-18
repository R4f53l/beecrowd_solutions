#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n, first = 1; 
    while(cin >> n, n){             
        while(1){
            stack<int> s; 
            vector<int> v(n); 
            int current = 1, fimdobloco = 0;  
            for(auto &i: v){
                cin >> i;
                if(!i){
                    fimdobloco = 1;  break;
                }
            }
            if(fimdobloco) break;
            int i = 0; 
            while(current <= n){
                s.push(current);
                while(!s.empty() && s.top() == v[i]){                    
                    s.pop(); i++;   
                }            
                current++;      
            }
            cout << (s.empty() ? "Yes" : "No") << endl;
            
        }
        cout << endl;
    }
}