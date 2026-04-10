#include <stdio.h> 
#include <string.h> 

int main () {
    int c; 
    char s [21];
    while(scanf("%s%d", s, &c)!=EOF){
        char inv[21]; 
        int i, cont = 0; 
        printf("$");
        for(i=0; s[i]; i++){
            if(i && i%3 == 0) inv[cont++] = ',';
            inv[cont++] = s[strlen(s)-i-1];
        }
        for(i=cont-1; i>=0; i--)
            printf("%c", inv[i]);
        printf(".%02d", c);
        printf("\n");
    }
    
}