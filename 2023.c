#include <stdio.h>
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 

typedef struct nodo {
    char inf[81];
    struct nodo *next; 
}NODO; 

typedef NODO* LISTA_ORD; 

void cria_lista (LISTA_ORD*l){
    *l = NULL;
}

int tam (LISTA_ORD l){
    int cont = 0; 
    while(l){
        cont++; 
        l = l->next; 
    }
    return cont; 
}

void ins (LISTA_ORD *l, char *s){
    NODO *novo = (NODO*) malloc(sizeof(NODO));
    strcpy(novo->inf, s);

    if(!(*l) || strcasecmp((*l)->inf, s) < 0){
        novo->next = *l; 
        *l = novo; 
    }

    else {
        NODO*aux = *l; 
        for(; aux->next && strcasecmp((aux->next)->inf, s) > 0; aux = aux->next); 
            novo->next = aux->next; 
            aux->next = novo; 
    }

}







int main () {
    char s[81][1000], aux[81];
    int i = 0, j; 
    LISTA_ORD l;
    cria_lista(&l);
    while(~scanf(" %[^\n]", aux))        
        ins(&l, aux);      
    printf("%s\n", l->inf);
    
    
}