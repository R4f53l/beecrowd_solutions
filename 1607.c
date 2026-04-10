#include <stdio.h>
#include <string.h>
 
int main() {
    int n, i; 
    scanf("%d", &n);
    while(n--){
        char s[10001], s2[10001]; 
        int soma = 0;        
        scanf("%s %s", s, s2);       
        int cont = 0; 
        for(i=0; s[i]; i++){
            if(s[i]<=s2[i])
                soma+= s2[i] - s[i];
            else 
                soma+= 26+s2[i] - s[i];
        }
            
        
        
        printf("%d\n", soma);
    }
 
    return 0;
}