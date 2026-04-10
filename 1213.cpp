#include <bits/stdc++.h> 

using namespace std; 

int main (){
    int n; 

    while(cin >> n){
        int a = 1, c = 0, aux = 1; 
        while(a){
            a = aux;
            aux = (aux*10 + 1) % n; 
            c++;
        }
        cout << c << endl;
    }
}