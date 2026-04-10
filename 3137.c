#include <stdio.h>
#include <string.h>
 
int main() {
    char s[10];
    int a, soma=0;
    scanf("%d", &a);
    while(a){
        sprintf(s, "%d", a);
        soma += strlen(s);
        a--;
    }
    printf("%d\n", soma);
 
    return 0;
}