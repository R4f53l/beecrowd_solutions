#include <stdio.h>
#include <stdlib.h> 



int m;

int comp (void const*a, void const*b){
    if(((*(int*)a%m)) == ((*(int*)b%m))){
        if((abs(*(int*)a%2)) == abs((*(int*)b%2))){
            if((*(int*)a%2) != 0)
                return *(int*)b - *(int*)a;                
            
            else
                return *(int*)a - *(int*)b;                
            
        }             
        else{
            if(abs(*(int*)a%2)) return -1; 
            else return 1; 
        }
    }
    else return (((*(int*)a%m)) - ((*(int*)b%m)));
} 
 
int main() {
    int n;  
    while(scanf("%d%d", &n, &m), n){
        int i, v[n];
        for(i=0; i<n; i++)
            scanf("%d", v+i);
        qsort(v, n, sizeof(int), comp);
        printf("%d %d\n", n, m);
        for(i=0; i<n; i++)
            printf("%d\n", v[i]);        
    }
    printf("0 0\n");
 
    return 0;
}