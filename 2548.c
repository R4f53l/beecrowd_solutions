#include <stdio.h> 
#include <stdlib.h> 

int comp (void const *a, void const *b){
    return *(int*)b - *(int*)a;
}

int main () {
    int m, n; 
    while(~scanf("%d%d", &m, &n)){
        int v[m], i, s = 0; 
        for(i=0; i<m; i++)
            scanf("%d", v+i);
        qsort(v, m, sizeof(int), comp);        
        for(i=0; i<n; i++)            
            s+= v[i];        
        printf("%d\n", s);
    }
}