#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct nodo {
    int inf; 
    struct nodo * next;
}NODO; 

typedef NODO * PILHA_ORD; 

void cria_pilha (PILHA_ORD *p){
    *p = NULL; 
}

int eh_vazia (PILHA_ORD p){
    return (!p);
}

int tam (PILHA_ORD p){
    int cont = 0; 
    while(p){
        cont++; 
        p = p->next; 
    }
    return cont;
}

void push (PILHA_ORD *p, int v){
    NODO *novo; 
    novo = (NODO*)malloc(sizeof(NODO));
    if(!novo){
        printf("Erro na alocacao!\n");
        exit(1);
    }
    novo->inf = v; 
    if(!(*p) || v < (*p)->inf){
        novo->next = *p; 
        *p = novo; 
    }
    else {
        NODO *aux; 
        for(aux = *p; aux->next && v > (aux->next)->inf; aux = aux->next);
            novo->next = aux->next; 
            aux->next = novo; 
    }
}

int top_pop (PILHA_ORD *p){
    if(!*p){
        printf("EMPTY!\n");
        exit(2);
    }
    int aux = (*p)->inf; 
    NODO *a = *p; 
    *p = (*p)->next; 
    free(a);
    return aux; 
}

void imprime (PILHA_ORD p){
    while(p){
        printf("%d", p->inf);
        p = p->next; 
    }
}

int main () {
    PILHA_ORD p; 
    cria_pilha (&p);
    push(&p, 5);
    push(&p, 3);
    push(&p, 7);
    push(&p, 10);
    push(&p, 2);
    imprime(p);
}