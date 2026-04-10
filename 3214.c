#include <stdio.h> 
int main () {
    int a, b, c, soma, cont = 0; 
    double d, armaz, t;  
    scanf("%d %d %d", &a, &b, &c);
    soma = a + b; 
    d = (float)soma/(float)c;    
    armaz = d;     
    while(d>=c){
        cont++;
        d++;        
        d-=c;        
    }  
    t = cont + armaz; 
    if(t<1)
        t = 0; 
    printf("%.0f\n", t);
}