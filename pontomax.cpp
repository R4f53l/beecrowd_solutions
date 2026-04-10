#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int f (int x){
    return -(x * x) + 2 * x + 1; //f(x) < f(x + 1)
}

int busca_binaria (){
    int x = -5; 
    for(int b = 16; b >= 1; b /= 2){
        while(f(x + b) < f (x + b + 1)) x += b;         
    }
    return x + 1; 
}

int main (){

    cout << "ponto maximo: " << f(busca_binaria()) << endl;
    cout << "valor do ponto maximo: " << busca_binaria() << endl;

}