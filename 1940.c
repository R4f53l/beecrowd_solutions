#include <stdio.h> 
int main () { 
    int j, r, a, soma = 0, maior = 0, pos, i, z; 
    scanf("%d", &j);    
    scanf("%d", &r);
    for(z=0; z<r*j; z++){
        scanf("%d", &a);
        soma += a; 
        if(!(z%r)){
            maior = maior >= soma? maior: soma; 
            pos = i+1; 
        }  
    }
    
    printf("%d\n", pos);
    







    return 0;
}