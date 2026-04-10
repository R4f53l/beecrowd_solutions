#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct nodo {
    char inf [51]; 
    struct nodo * next; 
}NODO;

typedef NODO* LISTA_ORD; 

void cria_lista (LISTA_ORD *l){
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

void ins (LISTA_ORD *l, char *v){
    NODO *novo = (NODO*)malloc(sizeof(NODO));
    strcpy (novo->inf, v);
    if(!(*l) || strlen(v) > strlen((*l)->inf)){
        novo->next = *l; 
        *l = novo; 
    }
    else {
        NODO *aux = *l; 
        for(aux; aux->next && strlen((aux->next)->inf) >= strlen(v); aux = aux->next); 
            novo->next = aux->next; 
            aux->next = novo;             
    }
    
}

void imprime (LISTA_ORD l){
    int cont = 0, t = tam(l);
    while(l){
        cont++; 
        if(cont == t)
            printf("%s", l->inf);
        else 
            printf("%s ", l->inf);
        l = l->next; 
    }
    printf("\n");
}


int main () {
    int n; 
    scanf("%d", &n);
    while(n--){
        LISTA_ORD l;
        cria_lista (&l);
        char s [51], o;
        scanf("%s", s);
        o = getchar ();
        while(o!='\n'){
            ins(&l, s);
            scanf("%s", s);
            o =  getchar();
        }
        ins (&l, s);
        imprime(l);
        
    }
    
}