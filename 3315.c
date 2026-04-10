#include <bits/stdc++.h>
#define tam 28
using namespace std; 
int main () {
    int i, a, soma = 0;
    vector<int> v; 
    for(i=0; i<tam; i++){
        scanf("%d", &a);
        soma+=a; 
    }
    while(soma){
        v.pushback(soma%2);
        soma/=2;        
    }
    reverse(v.begin(), v.end());
    for(i=0; i<v.size(); i++){
        printf("%d", v[i]);
    }
}