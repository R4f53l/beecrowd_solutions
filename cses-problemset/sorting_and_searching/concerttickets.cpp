#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int prices, customers; cin >> prices >> customers;

    deque<int> c(customers);
    multiset<int> p; 
    for(int i = 0; i < prices; i++){
        int a; cin >> a;
        p.insert(a); 
    } 
    for(auto &i: c) cin >> i;

        

    for(int i = 0; i < c.size(); i++){        
        auto it = p.upper_bound(c[i]);//retorna um iterator para o primeiro elemento > c[i] 
        
        
        if(it == p.begin()) cout << "-1" << endl;
        else{
            it--; 
            cout << *(it) << endl;
            p.erase(it);
        }

         
        

    }



}