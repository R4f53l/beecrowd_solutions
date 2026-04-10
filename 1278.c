#include <stdio.h>
#include <ctype.h> 
#include <string.h> 

int main() {
    int n, maior = 0, first = 1;     
    while(scanf("%d", &n), n){
        char s2[101][101];
        if(!first) printf("\n"); 
        first = 0; 
        
        for(int i = 0; i<n; i++){
            int c = 0;
            char s[101], s1 [101]; 
            scanf(" %[^\n]", s);
            for(int j = 0; s[j]; j++){
                if(isalpha(s[j]))
                    s1[c++] = s[j];
                else {
                    if(isalpha(s[j+1]))
                        s1[c++] = s[j];
                }
                
            }            
            s1[c] = '\0';             
            maior = maior < c ? c : maior;
            strcpy(s2[i], s1);
        }
        
        for(int i = 0; i<n; i++){
            for(int j = strlen(s2[i]); j<maior; j++)
                printf(" ");
            printf("%s\n", s2[i]);
        }
    }
    

    return 0;
}