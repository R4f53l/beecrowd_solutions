#include <stdio.h> 
#include <stdlib.h> 

typedef struct nodo {
    int inf; 
    struct nodo *left; 
    struct nodo *right;
}NODO; 
typedef NODO * ARV_BIN; 

ARV_BIN push (ARV_BIN a, int v){
    if(!a){
        a = (NODO*)malloc(sizeof(NODO));
        a->inf = v; 
        a->left = a->right = NULL;
    }
    if(a->inf > v)
        a->left = push(a->left, v);
    else 
        a->left = push(a->right, v);
    return a; 
}

typedef struct node {
    ARV_BIN inf; 
    struct nodo *next; 
}NODE; 

typedef struct{
    NODE *inicio; 
    NODE* fim; 
}DESCRITOR; 

typedef DESCRITOR * FILA_ENC; 

void cria_fila (FILA_ENC *f){
    *f = (DESCRITOR*)malloc(sizeof(DESCRITOR));
    if(!*f){
        printf("Erro na alocacao!\n");
        exit(1);
    }
    (*f)->inicio = (*f)->fim = NULL; 
}

int eh_vazia (FILA_ENC f){
    return (!f->inicio);
}

void ins (FILA_ENC f, NODO a){
    NODO *novo; 
    novo = (NODO*)malloc(sizeof(NODO));
    if(!novo){
        printf("Erro na alocacao!\n");
        exit(2);
    }
    novo->inf = a; 
    novo->next = NULL; 
    if(!f)
        f->inicio = novo;   
    else 
        f->fim->next = novo; 
    f->fim = novo; 
}

int main () {
    int c, n, nmb;
    scanf("%d", &c);
    while(c--){
        ARV_BIN a = NULL; 
        scanf("%d", &n);
        while(n--){
            scanf("%d", &nmb);
            a = push(a, nmb);           
        }
        if(a){
            ins (f, a);
            while(!eh_vazia(f)){

            
            }
        }
    }
}

