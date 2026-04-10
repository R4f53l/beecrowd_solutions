#include <stdio.h> 
#include <stdbool.h> 
#define max 1001
int main () {
    int i, j, v[1000], cont = 0, c, aux[1000], conta = 0, n, ind; 
    for(i=1; i<max; i++){
        
        c = 0; 
        
        for(j=1; j<max; j++)
            if(i%j==0) c++; 
        
        
        if(c == 2) v[cont++] = i; 
    }
    for(i=0; i<cont; i++){
        
        if(v[i] + 2 == v[i+1] || v[i] - 2 == v[i-1]) aux[conta++] = v[i];
        
        
    }
    
    scanf("%d", &n);

    for(i=0; i<conta; i++) {
        if(aux[i] <= n) ind = i;  
    }

    printf("%d %d\n", aux[ind-1], aux[ind]);
    
    
    
    
   
    
}