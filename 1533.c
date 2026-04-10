#include <stdio.h> 
int main () {
    int a, i, maior; 
    while(scanf("%d", &a), a){
        int s, v[200] = {0};
        for(i=0; i<a; i++){             
            scanf("%d", &s);
            maior = maior<s?s:maior;
            v[i] = s; 
        }
        sort(v);
        for(i=1; i<=maior; i++){
            printf("%d\n", v[i]);
        }
        
        
    }



}