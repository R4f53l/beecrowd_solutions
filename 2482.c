#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#define max 101
char t [max];


typedef struct nodo {
    char idioma [max], traducao [max];
    struct nodo *left; 
    struct nodo *right; 
}arv; 

arv* push (arv *a, char *i, char *s){
    if(!a){
        a = (struct nodo*) malloc(sizeof(struct nodo));
        strcpy(a->idioma, i), strcpy(a->traducao, s);
        a->left = a->right = NULL; 
    }
    else if (strcmp(a->idioma, i) > 0)
        a->left = push(a->left, i, s);
    else 
        a->right = push(a->right, i, s);
    return a; 
}

int busca (arv *a, char *i){
    if(!a)
        return 0; 
    if(!strcmp(a->idioma, i)){
        strcpy(t, a->traducao);
        return 1; 
    }
    else if(strcmp(a->idioma, i) > 0)
        return busca(a->left, i);
    else 
        return busca (a->right, i);
}

int main() {
    int n; 
    char nome [max], lingua [max], trad [max];
    arv *a = NULL; 
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf(" %[^\n] %[^\n]", lingua, trad);
        a = push(a, lingua, trad);
    }
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf(" %[^\n] %[^\n]", nome, lingua);
        if(busca (a, lingua)){
            printf("%s\n%s\n\n", nome, t);
        }
        
        
    }
 
    return 0;
}