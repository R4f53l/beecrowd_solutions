#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>

int ordena (const void *a, const void *b){
    return *(int*) a - *(int*)b; 
}

int busca (int *v, int n, int a){
    int inicio = 0, fim = n; 
    while(inicio < fim){
        int meio = (inicio + fim) / 2;
        if(v[meio] < a) inicio = meio + 1; 
        else fim = meio; 
    }
    return v[inicio] == a ? (inicio + 1):  0; 
}

int main () {
    int n, q, c = 1; 
    while(scanf("%d%d", &n, &q), n, q){        
        int i, v[n], a, r;           
        for(i=0; i<n; i++)
            scanf("%d", v+i);
        qsort(v, n, sizeof(int), ordena);  
        printf ("CASE# %d:\n", c++);     
        for(i=0; i<q; i++){
            scanf("%d", &a);
            r = busca (v, n, a);                             
            if(r) printf("%d found at %d\n", a, r);
            else  printf("%d not found\n", a);               
        }
             
    }
}

