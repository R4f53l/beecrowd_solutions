#include <stdio.h> 
int main () {
    int n, v [20000], maior = 0, i; 
    scanf("%d", &n); 
    while(n--){
        int x; 
        scanf("%d", &x);
            v[x]++;
        maior = maior<x? x: maior;
    }
    for(i=1; i<=maior; i++){
        if(v[i])
        printf("%d aparece %d vez(es)\n", i, v[i]);
    }
}