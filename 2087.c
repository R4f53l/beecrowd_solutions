#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
struct palav {
    char s [110];
};

int cmp (void const*a, void const*b){
    struct palav x = *(struct palav*)a, y = *(struct palav*)b; 
    return strcmp(x.s, y.s);
}
 
int main() {
    int t; 
    while(scanf("%d", &t), t){
        struct palav v[t];
        int i, b = 1; 
        for(i=0; i<t; i++)
            scanf("%s", v[i].s);
        qsort(v, t, sizeof(struct palav), cmp);
        for(i=0; i<t-1; i++){
            char *p = strstr(v[i+1].s, v[i].s); 
            if(p){
                if(strlen(p) != strlen(v[i].s)){
                    b = 0; 
                    break;
                }
                else if(!strcmp(p, v[i].s)){
                    b = 0; 
                    break; 
                }
            }
        }
        printf("Conjunto %s\n", b? "Bom" : "Ruim");
            
    }
   
 
    return 0;
}