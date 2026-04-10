#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
int main () {
    int i, contx = 0, conto = 0;
    char s[4];    
    scanf("%s", s);    
    for(i=0; s[i]; i++){
        if(s[i]=='O') conto++;
        else contx++;
    }
    if(s[0] == s[1] && s[1] == s[2])
        printf("?\n");

    else if(s[0]=='O' && conto==2) 
        printf("?\n");
    
    else if(conto!=2){
        if(s[0] == 'X' && s[1] == 'X' || s[1] == 'X' && s[2] == 'X')
            printf("Alice\n");
        else 
            printf("*\n");        
    }
    else if(s[0] == 'X' && conto == 2)
        printf("?\n");

    return 0;
}