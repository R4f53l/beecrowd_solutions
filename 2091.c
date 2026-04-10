#include <stdio.h> 
#include <stdlib.h> 
#define ll long long

int compara (void const *a, void const *b){
    if(*(int*)a < *(int*)b)
        return -1;            // vem antes 
    else if (*(int*)a > *(int*)b)
        return 1;             // vem depois 
    else 
        return 0;
}

int main () {
    int n; 
    while(scanf("%d", &n), n){
        int a, i; 
        ll v[100001];
        scanf("%d", &a);
        for(i=0; i<a; i++)
            scanf("%lld", &v[i]);
        for(i=0; i<a; i++)
            printf("%lld", v[i]);
        
       
    }
    
}