#include <stdio.h> 
#include <string.h> 

int main () {
    char s [] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./", s1[1001];    
    int i; 
    while(fgets(s1, 1001, stdin) != NULL){        
        for(i=0; s1[i]; i++){
            char *p = strchr (s, s1[i]);         
            if(p){
                p-=1; 
                s1[i] = p[0];  
            }   
        }
        s1[i] = 0;
        printf("%s", s1);
    }
}