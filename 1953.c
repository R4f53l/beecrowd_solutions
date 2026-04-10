#include <stdio.h>
#include <string.h> 
int main() {
    int n; 
    while(~scanf("%d", &n)){
        int epr = 0, ehd = 0, i = 0; 
        while(n--){
            int m; 
            char s[101]; 
            scanf("%d%s", &m, s);
            if(!strcmp(s, "EPR")) epr++; 
            else if(!strcmp(s, "EHD")) ehd++; 
            else i++; 
        }
        printf("EPR: %d\n", epr);
        printf("EHD: %d\n", ehd);
        printf("INTRUSOS: %d\n", i);
    }
 
    return 0;
}