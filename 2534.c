#include <stdio.h>
#include <stdlib.h> 
 
int ordena (const void *a, const void *b){
    if(*(int*)a < *(int*)b)
        return 1; //vem antes
    else if(*(int*)a > *(int*)b)
        return -1; //vem depois
    else 
        return 0;
} 
 
int main() {
    int n, q;
    while(scanf("%d%d", &n, &q) != EOF){
        int i, v[n], t; 
        for(i=0; i<n; i++)
            scanf("%d", &v[i]);
            
        qsort(v, n, sizeof(int), ordena);
        
        for(i=0; i<q; i++){
            scanf("%d", &t);
            printf("%d\n", v[t-1]);
        }
        
        
    }
    
 
    return 0;
}