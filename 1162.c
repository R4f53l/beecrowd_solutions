#include <stdio.h> 
#include <stdlib.h> 

int bsort (int *v, int n){
    int i, j, cont = 0; 
    for(i=1; i<n; i++){
        for(j=0; j<n-i; j++){
            int aux;
            if(v[j] > v[j+1]){
                cont++; 
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux; 
            }
        }
    }
    return cont; 
}

int main () {
    int n, i; 
    scanf("%d", &n);
    while(n--){
        int l, *v;
        scanf("%d", &l);
        v = (int*)malloc(sizeof(int)*l);        
        for(i=0; i<l; i++)
            scanf("%d", v+i);
        printf("Optimal train swapping takes %d\n swaps.\n", bsort(v, l));
    }
}