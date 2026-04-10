#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct nodo {
    char inf [21];
    struct nodo * next;
}NODO; 

typedef NODO * LISTA_ENC; 

void cria_lista (LISTA_ENC *l){
    *l = NULL;
}

int eh_vazia (LISTA_ENC l){
    return (!l);
}

int tam (LISTA_ENC l){
    int cont; 
    while(l){
        cont++;
        l = l->next; 
    }
    return cont; 
}

void ins (LISTA_ENC *l, int pos, char *s){  
    NODO *novo;   
    if(pos < 1 || pos > tam(*l)+1){
        printf("Erro! Posicao invalida!\n");
        exit(1);
    }
    
    novo = (NODO*)malloc(sizeof(NODO));
    if(!novo){
        printf("Erro na alocacao!\n");
        exit(2);
    }

    strcpy (novo->inf, s);

    if(pos == 1){
        novo -> next = *l; 
        *l = novo; 
    }
    else {
        NODO *aux; 
        for(aux = *l; pos>2; aux = aux->next, pos--);
            novo -> next = aux -> next; 
            aux -> next = novo; 
    }
}

void imprime (LISTA_ENC l){
    while(l){
        printf("%s ", l->inf);
        l = l->next; 
    }
}

int main () {
    int pos = 1; 
    char s[200], ind[200], *t; 
    LISTA_ENC latual, lnova; 
    cria_lista(&latual);
    cria_lista(&lnova);
    scanf("%s", s);
    t = strtok(s, " ");
    while(t)
        ins(&latual, pos++, t);
    pos = 0;
    scanf("%s", s);
    t = strtok(s, " ");
    while(t)
        ins(&lnova, pos++, s);
    scanf("%s", ind);
    imprime(latual);
    imprime(lnova);
    
    
    
}

