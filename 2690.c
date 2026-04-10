#include <stdio.h>
#include <string.h>  
#define max 12
int main() {
    char s [10][10] = {"GQaku", "ISblv", "EOYcmw", "FPZdnx", "JTeoy", "DNXfpz", "AKUgq", "CMWhr", "BLVis", "HRjt"}, s2[30];
    int i, j, n; 

    scanf("%d", &n);

    while(n--){        
        int cont = 0; 

        scanf(" %[^\n]", s2);    
        
            for(j=0; s2[j]; j++){
                for(i=0; i<10; i++){
                    char *c = strchr (s[i], s2[j]);  
                    if(c){
                        cont++;
                        printf("%d", i);
                        break;
                    }
            }      
            if(cont == 12) break;
        }

        printf("\n");
        
    }
    
    
 
    return 0;
}