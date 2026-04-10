#include <stdio.h>

/*  1 3 5 4 2 * marcelo
    1 3 4 5 2 *carlos
    1 3 4 2 5 *marcelo
    1 3 2 4 5 *carlos
    1 2 3 4 5 *marcelo 
    
    1 5 3 4 2
    1 3 5 4 2
    1 3 4 5 2
    1 3 4 2 5
    1 3 2 4 5
    1 2 3 4 5
    
*/

int bsort (int *v, int n){
    int i, j, cont = 0; 
    for(i=1; i<n; i++){
        for(j = 0; j<n-i; j++){
            if(v[j] > v[j+1]){
                cont = 1 - cont; 
                int aux = v[j];
                v[j] = v[j+1]; 
                v[j+1] = aux; 
            }
        }
    }
    return cont; 
}

 
int main() {
    int n; 
    while(scanf("%d", &n), n){
        int i, v[n];
        for(i=0; i<n; i++)
            scanf("%d", v + i);
        int a = bsort(v, n);
        printf("%s\n", a ? "Marcelo" : "Carlos");
        
    }

    return 0;
}