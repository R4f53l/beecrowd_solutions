#include <stdio.h> 
int main () {
    int n, l, d, aux; 
    float lit;
    scanf("%d %d %d", &n, &l, &d);    
    lit = n * (d/1000.0);   
    aux = l; 
    while(lit>l){
        l+=aux; 
    }
    printf("%d\n", l);
}