#include <stdio.h>
#include <math.h> 
int main () {
    int n, cont = 0, second = 1;     
    while(scanf("%d", &n), n){            
        int x, y, c[300] = {0}, i, army=0, armx=0, first = 1; 
        double consmedio;
        if(second)
            second = 0;
        else printf("\n");
        for(i=0; i<n; i++){        
            scanf("%d %d", &x, &y);
            army+=y; 
            armx+=x; 
            c[y/x] += x;            
        }        
        printf("Cidade# %d:\n", ++cont);        
        for(i=0; i<300; i++){
            if(c[i]){
                if(first)
                    first = 0;
                else 
                    printf(" ");
                printf("%d-%d", c[i], i);
            }            
        }
        printf("\n");
        consmedio = (double)army/(double)armx;
        printf("Consumo medio: %.2lf m3.\n", floorf(consmedio*100)/100);        
        
        
    }   
    
}