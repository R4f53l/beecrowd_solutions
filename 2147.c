#include <stdio.h>
#include <string.h> 
 
int main() {
    int c; 
    scanf("%d", &c);
    while(c--){
        char s[10001];
        scanf("%s", &s);
        printf("%.2f\n", strlen(s)/100.0);
    }
 
 
    return 0;
}