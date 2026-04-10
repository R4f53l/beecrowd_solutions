#include <stdio.h>
#include <string.h> 

struct nome {
    char s[17];
    float v; 
}; 
 
int main() {
    int m, n, c = 0;
    float soma = 0; 
    struct nome v [100];
    scanf("%d%d", &m, &n);
    for(int i = 0; i<m; i++)
        scanf("%s%f", v[i].s, &v[i].v);
    for(int i = 0; i<n; i++){
        char string [51]
        while(scanf("%s", string), !strcmp(".", string)){
            for(int j = 0; j<m; j++)
                if(!strcmp(v[j].s, string)) soma += v[j].v;
        }        
        printf("%.0f", soma);
    }
 
    return 0;
}