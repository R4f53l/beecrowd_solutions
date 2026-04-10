#include <stdio.h>
 
int main() {
    int n; 
    while(~scanf("%d", &n)){
        for(int i = 1; i<=n; i++){
            
            printf("%*s", n-i-1, "");
            
            for(int z = 1; z<=(2*i)-1; z++)
                printf("*");
            
            printf("%*s", n-i-1, "");
            
            printf("\n");
            if((2*i)-1 == n) break;
        }
        for(int i = 1; i<=2; i++){
            printf("%*s", n-i-1, "");
            for(int z = 1; z<=(2*i)-1; z++)
                printf("*");
            printf("%*s", n-i-1, "");
            printf("\n");
        }
        printf("\n");
    }
    
 
    return 0;
}