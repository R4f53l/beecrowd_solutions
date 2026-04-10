#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define max 1001
#define maxs 21

typedef struct {
    int n; 
    char s[maxs];
}vector; 

int comp (void const*a, void const *b){
    vector x = *(vector*)a, y = *(vector*)b; 
    if(!(strlen(x.s) - strlen(y.s)))
        return x.n - y.n; 
    return strlen(x.s) - strlen(y.s);
}

int main () {
    
    vector v[max], names[max];
    int n, t = 0, c = 0, i; 
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        char s [maxs];
        scanf("%s", s);
        v[i].n = i; 
        strcpy(v[i].s, s);
    }

    qsort(v, n, sizeof(vector), comp);

    for(i = 0; i<n; i++){          
        if(strcmp(v[i].s,"0") && strlen(v[i].s) > t){
            strcpy(names[c].s, v[i].s);
            t = strlen(v[i].s);
            c++;                         
            strcpy(v[i].s, "0");
        }        
        if(c == n) break;
        if(i == n-1){ 
            i = -1; 
            t = 0;
        }
    }
   

    for(i = 0; i<n-1; i++){
        if(strlen(names[i].s) < strlen(names[i+1].s))
            printf("%s, ", names[i].s);
        else printf("%s\n", names[i].s);
    }
    printf("%s\n", names[n-1].s);

}