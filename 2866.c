#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 

int main () {
    int n; 
    scanf("%d", &n);
    while(n--){
        char s[10000], aux[10000];
        int cont = 0, i; 
        scanf("%s", s);
        for(i=0; s[i]; i++){
            if(islower(s[i]))
                aux[cont++] = s[i];
        }
        aux[cont] = 0; 
        for(i=0; aux[i]; i++)
            s[strlen(aux)-i-1] = aux[i];
        s[i] = 0; 
        printf("%s\n", s);
    }
}