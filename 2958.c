#include <stdio.h>
#include <stdlib.h> 

int compara (void const *a, void const *b){
    if(*(int*)a < *(int*)b)
        return 1; //vem depois
    else if (*(int*)a > *(int*)b)
        return -1; //vem antes
    else 
        return 0;
}

void imprimev (int *v, int a){
    int i;
    qsort(v, a, sizeof(int), compara);
    for(i=0; i<a; i++)
        printf("%dV\n", v[i]);
}

void imprimed (int *v, int a){
    int i;
    qsort(v, a, sizeof(int), compara);
    for(i=0; i<a; i++)
        printf("%dD\n", v[i]);
}
 
int main() {
    int n, m, i, j, n1, vetorv[1000], vetord[1000], v = 0, d = 0; 
    char c; 
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d\n%c", &n1, &c);
            switch(c){
                case 'V': 
                    vetorv[v++] = n1; 
                    break;
                case 'D':
                    vetord[d++] = n1; 
                    break;
            }
        }
    }
    imprimev(vetorv, v);
    imprimed(vetord, d);
    
   
 
    return 0;
}