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
    if(!*p)
        novo->inf = v; 
    else 
        novo->inf = (*p)->inf > v ? v : (*p)->inf; 

    novo->next = *p; 
    *p = novo; 
}

void pop (PILHA_ORD *p){
    if(!*p)
        printf("EMPTY\n");    
    else{
        NODO *a = *p; 
        *p = (*p)->next; 
        free(a);   
    }
}

int top (PILHA_ORD p){
    if(!p)
        return -1;
    else 
        return p->inf;
}



    



int main () {
    int n;    
    scanf("%d", &n);
    PILHA_ORD p; 
    cria_pilha (&p);
    while(n--){        
        int nmb; 
        char s[5];
        scanf("%s", s);
        if(!strcmp("PUSH", s)){
            scanf("%d", &nmb);
            push(&p, nmb);            
        }
        else if(!strcmp("POP", s))
            pop(&p);
        else{            
            if(top(p) == -1)
                printf("EMPTY\n");
            else 
                printf("%d\n", top(p));
        }
    }
}