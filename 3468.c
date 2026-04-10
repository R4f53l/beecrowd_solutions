#include <stdio.h> 
#include <ctype.h>
int main () {
    char s [100], c; 
    scanf("%s", s);
    c = tolower(s[0]);
    if(c=='c' || c == 'o')
        printf("mas\n");
    else
        printf("mais\n");
    





    return 0;
}