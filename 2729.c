#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct nodo {
    char inf[21]; 
    struct nodo *next; 
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

void ins (LISTA_ORD *l, char *s){
    NODO *novo = (NODO*) malloc(sizeof(NODO));
    strcpy(novo->inf, s);

    if(!(*l) || strcmp((*l)->inf, s) > 0){
        novo->next = *l; 
        *l = novo; 
    }

    else {
        NODO*aux = *l; 
        for(; aux->next && strcmp((aux->next)->inf, s) < 0; aux = aux->next); 
            novo->next = aux->next; 
            aux->next = novo; 
    }

}

int pertence (LISTA_ORD l, char *s){
    while(l){
        if(!strcmp(l->inf, s)) return 1; 
        l = l->next; 
    }
    return 0; 
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
    int n, i; 
    char o;     
    scanf("%d", &n);
    for(i=0; i<n; i++){
        LISTA_ORD l; 
        cria_lista (&l);
        char s[21]; 
        scanf("%s", s);
        o = getchar(); 
        if(!tam(l)) ins(&l, s);
        do{
            scanf("%s", s);
            o = getchar();            
            if(!pertence(l, s)) ins(&l, s);      
        }while(o!='\n');       
        imprime(l);      
        
            
    }
    
}