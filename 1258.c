#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
struct camisas {
    char n [101], cor [9], t[2];
};

int comp (const void *a, const void *b){
    if((!strcmp((*(struct camisas*)a).cor, (*(struct camisas*)b).cor))){
        if((!strcmp((*(struct camisas*)b).t, (*(struct camisas*)a).t)))
            return strcmp((*(struct camisas*)a).n, (*(struct camisas*)b).n);
        else 
            return strcmp((*(struct camisas*)b).t, (*(struct camisas*)a).t);
    }
    else return strcmp((*(struct camisas*)a).cor, (*(struct camisas*)b).cor);
}

int main() {
    int n, first = 1;  
    while(scanf("%d", &n), n){
        struct camisas v[n];
        int i; 
        if(first)
            first = 0; 
        else printf("\n");
        
        for(i=0; i<n; i++){
           scanf(" %[^\n]", v[i].n);
           scanf("%s %s", v[i].cor, v[i].t);
        }
        qsort(v, n, sizeof(struct camisas), comp);
    
        for(i=0; i<n; i++)
            printf("%s %s %s\n", v[i].cor, v[i].t, v[i].n);
        
    }
    
    return 0;
}