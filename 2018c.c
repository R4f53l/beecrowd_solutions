#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

const int MAX = 1e3 + 1; 

typedef struct{
    char s[1001]; 
    int o, p, b; 
}quadro; 

int comp (const void *a, const void *b){
    quadro x = *(quadro*)a, y = *(quadro*)b; 
    if(x.o == y.o){
        if(x.p == y.p){
            if(x.b == y.b)
                return strcmp(x.s, y.s);     // -1 o primeiro elemento vem antes, 1 o primeiro elemento vem depois, 0 são iguais. 
            else return x.b < y.b;               //x.b - y.b  -> -1, entao, o primeiro elemento vem antes, ou seja, do menor p maior. y.b - x.b, 
            
        }
        else return x.p < y.p; 
    }
    else return x.o < y.o;     
}

int main(){
    char e[MAX], p1[MAX], p2[MAX], p3[MAX];
    int cont = 0; 
    quadro v[MAX];
    for(int i = 0; i<MAX; i++){
        v[i].o = 0; v[i].p = 0; v[i].b = 0; 
    }
    while(~scanf("%[^\n]", e), strcmp(e, "vasco")){
        scanf(" %[^\n] %[^\n] %[^\n] ", p1, p2, p3);
        
        int v1 = 0, v2 = 0, v3 = 0; 
        
        for(int i = 0; i<cont; i++){
            if(!strcmp(v[i].s, p1)){
                v[i].o++; v1 = 1; 
            }
            if(!strcmp(v[i].s, p2)){
                v[i].p++; v2 = 1; 
            }    
            else if(!strcmp(v[i].s, p3)){ 
                v[i].b++; v3 = 1; 
            }
        }
        
        if(!v1) {
            strcpy (v[cont].s, p1); v[cont].o++; 
            cont++;
        }
        if(!v2){
            strcpy (v[cont].s, p2); v[cont].p++;
            cont++;
        }
        if(!v3){
            strcpy (v[cont].s, p3); v[cont].b++;
            cont++;
        }
        
    }
    qsort(v, cont, sizeof(quadro), comp);
    
    printf("Quadro de Medalhas\n");
    
    for(int i = 0; i<cont; i++)
        printf("%s %d %d %d\n", v[i].s, v[i].o, v[i].p, v[i].b);
}
