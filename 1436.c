#include <stdio.h>
#include <stdlib.h> 

int compara (const void *a, const void *b){
    if(*(int*)a < *(int*)b)
        return 1; 
    else if(*(int*)a > *(int*)b)
        return -1; 
    else 
        return 0; 
}
 
int main() {
    int t, c = 1; 
    scanf("%d", &t);
    while(t--){
        int n, i, v[10]; 
        scanf("%d", &n);
        for(i=0; i<n; i++)
            scanf("%d", v+i);
        qsort (v, n, sizeof(int), compara);
        n-=1; 
        printf("Case %d: %d\n", c++, v[n/2]);
    }
 
    return 0;
}