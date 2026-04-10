#include <stdio.h> 

int main () {
    int m, n, a; 
    while(~scanf("%d%d", &m, &n)){    
        int s = 0; 
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                scanf("%d", &a);
                s += a; 
            }
        }
        printf("%d saca(s) e %d litro(s)\n", s/60, s%60);
    }
   
}