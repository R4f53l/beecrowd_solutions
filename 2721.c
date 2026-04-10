#include <stdio.h> 
#define t 30

 

int qmov (int *v){
    v[0] = 1; 
    for(int i=1; i<=t; i++)
        v[i] = (v[i-1] * 2) + 1; 
}

int main () {
    int n, c = 1, v[t];
    qmov(v);
    while(scanf("%d", &n), n)
        printf("Teste %d\n%d\n\n", c++, v[n-1]);
    
}