#include <stdio.h> 
#include <stdlib.h> 
//o retorno define quem vem antes e quem vem depois: 
/*Se o retorno eh > 0, entao vem depois, < 0, vem antes e == 0 nao muda.*/

int ordena (const void *a, const void *b){ 
    if(*(int*)a == *(int*)b) 
        return 0; //sao iguais; 
    else if (*(int*)a < *(int*) b)                                
        return -1; //vem antes 
    else    
        return 1; 
}



int main () {
    int n, a, i, vp[100000], vi[100000], p = 0, im = 0; 
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &a);
        if(!(a%2))
            vp[p++] = a; 
        
        else
            vi[im++] = a; 
        
    }
    qsort(vp, p, sizeof(int), ordena);
    qsort(vi, im, sizeof(int), ordena);
    for(i=0; i<p; i++)
        printf("%d\n", vp[i]);
    for(i=im-1; i>=0; i--)
        printf("%d\n", vi[i]);

}