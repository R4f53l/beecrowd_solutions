#include <stdio.h>
 
int main() {
    char s [51];
    while(fgets(s, 51, stdin)!=NULL){
        int i, ct = 0, ca = 0;
        for(i=0; s[i]; i++){
            if(s[i] == '_'){
                printf("%s", ct ? "</i>" : "<i>");
                ct = 1 - ct; 
            }
            else if(s[i] == '*'){
                printf("%s", ca ? "</b>" : "<b>");
                ca = 1 - ca;
            }
            else printf ("%c", s[i]);
        }       
    }
    printf("\n");
 
    return 0;
}