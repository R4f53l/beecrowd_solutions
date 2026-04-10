#include <stdio.h> 
#include <stdlib.h> 

typedef struct nodo {
    int info; 
    struct nodo * left; 
    struct nodo * right; 
    struct nodo * father; 
}NODO; 
typedef NODO * ARV_BIN_BUSCA; 

void maketree (ARV_BIN_BUSCA *a, int v){
    *a = (NODO*)malloc(sizeof(NODO));
    if(!*a){
        printf("Erro na alocacao!\n");
        exit(1);
    }
    (*a)->info = v; 
    (*a)->left = NULL; 
    (*a)->right = NULL; 
    (*a)->father = NULL;     
}

void setleft (ARV_BIN_BUSCA a, int v){
    a->left = (NODO*) malloc (sizeof(NODO));
    if(!a->left){
        printf("Erro na alocacao!\n");
        exit(2);
    }    
    a->left->info = v; 
    a->left->father = a; 
    a->left->left = NULL;
    a->left->right = NULL;     
}

void setright (ARV_BIN_BUSCA a, int v){
    a->right = (NODO*)malloc(sizeof(NODO));
    if(!a->right){
        printf("Erro na alocacao!\n");
        exit (3);
    }
    a->right->info = v; 
    a->right->father = a; 
    a->right->left = NULL; 
    a->right->right = NULL;
}

int info (ARV_BIN_BUSCA a){
    return a->info; 
}

ARV_BIN_BUSCA left (ARV_BIN_BUSCA a){
    return a->left; 
}

ARV_BIN_BUSCA right (ARV_BIN_BUSCA a){
    return a->right;
}

ARV_BIN_BUSCA father (ARV_BIN_BUSCA a){
    return a->father; 
}

int isleft (ARV_BIN_BUSCA a){
    if(a->father){
        if((a->father)->left == a) return 1;     
    }
    return 0;
}

ARV_BIN_BUSCA brother (ARV_BIN_BUSCA a){
    if(a->father){
        if(isleft(a))
            return (a->father)->right;
        else 
            return (a->father)->left; 
    }
    return NULL;
}

int isright (ARV_BIN_BUSCA a){
    if(a->father)
        return (!isleft(a));
    return 0;    
}

void ins_ele (ARV_BIN_BUSCA *arv, int v){    
    if(!*arv)
        maketree (arv, v);
    else {
        NODO *father = *arv; 
        do  {
            if(v < father->info){
                if(father->left)
                    father = father->left; 
                else {
                    setleft (father, v);
                    break;
                }
            }
            else {
                if(father->right)
                    father = father->right; 
                else{
                    setright(father, v);
                    break;
                } 
            }
        } while(1);
    }        
}


typedef struct node {
    ARV_BIN_BUSCA inf; 
    struct node * next; 
}NODE; 

typedef struct {
    NODE * inicio; 
    NODE * fim; 
}DESCRITOR; 

typedef DESCRITOR * FILA_ENC; 

void cria_fila (FILA_ENC *f){
    *f = (DESCRITOR*)malloc(sizeof(DESCRITOR));
    if(!*f){
        printf("Erro na alocacao!\n");
        exit(4);
    }
    (*f) -> inicio = (*f) -> fim = NULL; 
}

void ins (FILA_ENC f, ARV_BIN_BUSCA v){
    NODE *novo; 
    novo = (NODE*)malloc(sizeof(NODE));
    novo->inf = v; 
    novo->next = NULL;
    if(!f->inicio)
        f->inicio = novo; 
    else 
        f->fim->next = novo; 
    f->fim = novo; 
}

int eh_vazia (FILA_ENC f){
    return (!f->inicio);
}

ARV_BIN_BUSCA cons (FILA_ENC f){
    return f->inicio->inf;
}

void ret (FILA_ENC f){
    NODE *aux = f->inicio; 
    f->inicio = f->inicio->next; 
    if(!f->inicio)
        f->inicio = NULL;
    free(aux);
}


void percurso (ARV_BIN_BUSCA a, int i){
    FILA_ENC f; 
    cria_fila(&f);
    int aux = i;
    if(a){
        ins(f, a);
        while(!eh_vazia(f)){
            if(aux != 1)
                printf("%d ", info(cons(f)));
            else 
                printf("%d\n", info(cons(f)));
            if(left(cons(f)))
                ins(f, left(cons(f)));
            if(right(cons(f))) 
                ins(f, right(cons(f)));
            --aux;
            ret(f);
            
        }
    }
}

int main () {
    int n, cont = 0;
    scanf("%d", &n);
    while(n--){
        int a, t, i;
        ARV_BIN_BUSCA arv;        
        scanf("%d", &a);
        for(i=0; i<a; i++){
            scanf("%d", &t);
            if(!i)                
                maketree(&arv, t);   
            else                                 
                ins_ele(&arv, t);
        }
        printf("Case %d:\n", ++cont);                  
            percurso(arv, a);   
        printf("\n");      
    }
}
