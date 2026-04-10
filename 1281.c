#include <stdio.h> 
#include <string.h> 
struct produtos {
    char inf [51];
    float v; 
};

int main () {
    int n; 
    scanf("%d", &n);
    while(n--){
        struct produtos v[100];        
        int m, i = 0; 
        scanf("%d", &m);
        for (i = 0; i<m; i++){
            char s[51]; 
            float p; 
            scanf("%s %f",  v[i].inf, &v[i].v);
        }
        int q, r; 
        char nome[51];
        float s = 0; 
        scanf("%d", &q);
        for(int j = 0; j<q; j++){
            scanf("%s %d", nome, &r);
            for(int z = 0; z<m; z++){
                if(!strcmp(v[z].inf, nome)){
                    s+= v[z].v * r;
                    break;
                }
            }
        }
        printf("R$ %.2f\n", s);

    }
}