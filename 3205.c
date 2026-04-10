#include <stdio.h>

int main() {
    int n, c = 1;
    
    while(scanf("%d", &n), n){
        int soma = 0, a; 
        char t; 
        scanf("%d", &a);
        soma = a; 
        for(int i = 0; i<n-1; i++){
            scanf(" %c%d", &t, &a);
            if(t == '+')
                soma += a; 
            else if(t == '-')
                soma -= a; 
        }
        
        printf("Teste %d\n%d\n\n", c++, soma);
        
        
    
    }
 
    return 0;
}