#include <stdio.h> 
int main() {
    char s[27];
    while(scanf("%s", s) != EOF){
        char aux[27];
        int n, a, i;
        scanf("%d", &n);
        for(i=0; i<n; i++){
            scanf("%d", &a);
            aux[i] = s[a-1];
        }
        aux[i] = 0; 
        printf("%s\n", aux);
    }
    
 
    return 0;
}