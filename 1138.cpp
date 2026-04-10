#include <bits/stdc++.h> 
using namespace std; 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main () {_
    int a, b; 
    
    while(cin >> a >> b, a){
        vector<int> v(10, 0);
        for(int i = a; i<=b; i++){
            int aux = i; 
            while(aux){  
                v[aux%10]++; 
                aux/=10;
            }
        } 

        for(int i = 0; i<10; i++)
            cout << v[i] << " ";
        cout << endl;
    }
}