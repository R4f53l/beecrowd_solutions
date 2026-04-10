#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 

float soma;

typedef struct arv {
    char str[17];
    float inf; 
    struct arv *left;
    struct arv *right; 
}arv; 

arv* ins (struct arv *a, char *s, float v){
    if(!a){
        a = (struct arv*) malloc (sizeof(struct arv));       
        strcpy (a->str, s);
        a->inf = v;  
        a->left = a->right = NULL; 
    }
    else if (strcmp(a->str, s) > 0)
        a->left = ins (a->left, s, v);
    else if(strcmp (a->str, s) < 0)
        a->right = ins (a->right, s, v);     
    return a;    
}

_Bool busca (arv *a, char *s){
    if(!a)
        return false; 
    if(!strcmp(a->str, s)){
        soma += a->inf; 
        return true; 
    } 
    else if(strcmp(a->str, s) > 0) busca (a->left, s);
    else busca (a->right, s);
}

int main() {
    int m, n, c = 0;
    float v;    
    arv *a = NULL; 
    char s [17]; 
    scanf("%d%d", &m, &n);
    for(int i = 0; i<m; i++){
        scanf("%s%f", s, &v);
        a = ins(a, s, v);
    }
    for(int i = 0; i<n; i++){
        char string [51];
        _Bool p = false; 
        soma = 0; 
        while(scanf("%s", string), strcmp(".", string)){
            busca(a, string);
        }
        printf("%.0f\n", soma);
    }
 
    return 0;
}