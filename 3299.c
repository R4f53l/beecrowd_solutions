#include <stdio.h>
#include <stdbool.h>
int main () {   
    int i; 
    char s [100];
    bool m = false; 
    scanf("%s", s);
    for(i=0; s[i]; i++){
        if(s[i]=='1' && s[i+1]=='3')
            m = true;             
    }
    if(m)
        printf("%s es de Mala Suerte\n", s);
    else
        printf("%s NO es de Mala Suerte\n", s);







    return 0; 
}