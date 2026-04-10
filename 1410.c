#include <stdio.h>

int comp (void const *a, void const *b){
    return *(int*) a - *(int*) b; 
} 
 
int main() {
    int a, d; 
    while(scanf("%d%d", &a, &d), a, d){
        int va[a], vd[d], i; 
        for(i=0; i<a; i++)
            scanf("%d", va+i);
        for(i=0; i<d; i++)
            scanf("%d", vd+i);
        qsort(va, a, sizeof(int), comp);
        qsort(vd, d, sizeof(int), comp);
        if(va[0] < vd[1]) printf("Y\n");
        else printf("N\n");
        
        
    }
    
 
    return 0;
}