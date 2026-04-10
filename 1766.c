#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
 
struct elfos {
    char nome[101];
    int peso; 
    int idade; 
    float altura; 
};

int comp (void const*a, void const*b){
    if((*(struct elfos*)a).peso == (*(struct elfos*)b).peso){
        if((*(struct elfos*)a).idade == (*(struct elfos*)b).idade){
            if((*(struct elfos*)a).altura == (*(struct elfos*)b).altura){
                return strcmp((*(struct elfos*)a).nome, (*(struct elfos*)b).nome);
            }
            else{
                if((*(struct elfos*)a).altura < (*(struct elfos*)b).altura) return -1;
                else return 1; 
            }
        }
        else return (*(struct elfos*)a).idade - (*(struct elfos*)b).idade;
    }
    else return (*(struct elfos*)b).peso - (*(struct elfos*)a).peso; 
}

int main() {
    int t; 
    scanf("%d", &t);
    while(t--){
        struct elfos v [1000];
        int n, m, i;
        scanf("%d%d", &n, &m);
        for(i=0; i<n; i++)
            scanf("%s%d%d%f", v[i].nome, &v[i].peso, &v[i].idade, &v[i].altura);
        qsort(v, n, sizeof(struct elfos), comp);
        printf("CENARIO {1}\n");
        for(i=0; i<m; i++)
            printf("%d - %s\n", i+1, v[i].nome);
        
        
    }
 
    return 0;
}