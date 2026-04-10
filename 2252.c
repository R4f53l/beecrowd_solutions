#include <stdio.h> 
#include <stdlib.h> 
#define max 10

struct ord {
    float inf;  
    int ind; 
};

int comp (void const *a, void const *b){
    if((*(struct ord*)a).inf < (*(struct ord*)b).inf) return 1; 
    else if((*(struct ord*)a).inf > (*(struct ord*)b).inf) return -1;
    else return ((*(struct ord*)a).ind - (*(struct ord*)b).ind);    
}

int main () {    
    int n, c = 1; 
    while(~scanf("%d", &n)){
        struct ord v [max];
        int i; 
        float a; 
        for(i=0; i<max; i++){
            scanf("%f", &v[i].inf);             
            v[i].ind = i; 
        }            
        
        qsort(v, max, sizeof(struct ord), comp);     
        
        
        printf("Caso %d: ", c++);
        for(i=0; i<n; i++)
            printf("%d", v[i].ind);
        printf("\n");
        
    }
}