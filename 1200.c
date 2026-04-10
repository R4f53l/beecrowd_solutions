/*Questao:  1200 BeeCrowd
Estrutura de dado: Arvore binaria de busca. 
Enunciado: 
Marcela recebeu como trabalho de Algoritmos a tarefa de fazer um programa que implemente uma Arvore Binaria de Pesquisa (ou Busca). O Programa deve aceitar os seguintes comandos:
I n: Insere na arvore binaria de pesquisa o elemento n.
INFIXA: lista os elementos ja cadastrado segundo o percurso infixo
PREFIXA: lista os elementos ja cadastrado segundo o percurso prefixo
POSFIXA: lista os elementos ja cadastrado segundo o percurso posfixo
P n: pesquisa se o elemento n existe ou nao.
A qualquer momento pode-se inserir um elemento, visitar os elementos previamente inseridos na ordem infixa, prefixa ou posfixa ou ainda procurar por um elemento na arvore para saber se o elemento existe ou nao.Entrada
A entrada contem N operacoes utilizando letras (A-Z,a-z) sobre uma arvore binaria de Busca, que inicialmente se encontra vazia. A primeira linha de entrada contem a insercao de algum elemento. 
As demais linhas de entrada podem conter quaiquer um dos comandos descritos acima, conforme exemplo abaixo. O final da entrada é determinado pelo final de arquivo (EOF).
Obs: Considere que nao serao inseridos elementos repetidos na arvore.
Saida
Cada linha de entrada, com excecao das linhas que contem o comando "I", deve produzir uma linha de saida. A saida deve ser de acordo com o exemplo fornecido abaixo. Nao deve haver espaco em branco apos o ultimo 
caractere de cada linha, caso contrario, sua submissao recebera Presentation Error.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#define max 100

typedef struct nodo {
    char inf; 
    struct nodo *left; 
    struct nodo *right;
    struct nodo *father;  
}NODO; 
typedef NODO * ARV_BIN_BUSCA; 

char pref [max] = "";
char infi [max] = "";
char posf [max] = "";

int i = 0; 
int j = 0; 
int k = 0; 


void maketree (ARV_BIN_BUSCA *a, char l){
    *a = (NODO*)malloc(sizeof(NODO));
    if(!*a){
        printf("Erro na alocacao!\n");
        exit(1);
    }
    (*a)->inf = l; 
    (*a)->left = (*a)->right = (*a)->father = NULL;
}

void setleft (ARV_BIN_BUSCA a, char l){
    a->left = (NODO*)malloc(sizeof(NODO));
    if(!a->left){
        printf("Erro na alocacao!\n");
        exit(2);
    }
    a->left->inf = l; 
    a->left->father = a; 
    a->left->left= NULL; 
    a->left->right = NULL;     
}

void setright (ARV_BIN_BUSCA a, char l){
    a->right = (NODO*)malloc(sizeof(NODO));
    if(!a->right){
        printf("Erro na alocacao!\n");
        exit(3);
    }
    a->right->inf = l; 
    a->right->father = a; 
    a->right->left = NULL; 
    a->right->right = NULL;
}

char info (ARV_BIN_BUSCA a){
    return a->inf;
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

void ins_ele (ARV_BIN_BUSCA *a, char l){
    if(!*a)
        maketree (a, l);
    else{
        NODO *father = *a; 
        do{
            if(father->inf > l){
                if(father->left)
                    father = father->left; 
                else{ 
                    setleft(father, l); 
                    break;
                }
            }
            else{
                if(father->right)
                    father = father->right;
                else{  
                    setright(father, l);
                    break;
                }
            }
        }while(1);
    }
}

int busca (ARV_BIN_BUSCA a, char l){
    if(!a)
        return 0;
    if (a->inf == l) return 1; 
    
    if(a->inf > l)
        busca(a->left, l);
    else   
        busca(a->right, l);    
}

void prefixa (ARV_BIN_BUSCA a){
    if(a){
        pref[i++] = a->inf;
        prefixa(a->left);
        prefixa(a->right);
    }
    
}

void infixa (ARV_BIN_BUSCA a){
    if(a){
        infixa (a->left);
        infi[j++] = a->inf; 
        infixa (a->right);
    }
}

void posfixa (ARV_BIN_BUSCA a){
    if(a){
        posfixa (a->left);
        posfixa (a->right);
        posf[k++] = a->inf;
    }
}

void printprefixa (char *s){
    int z; 
    for(z = 0; z<i; z++){
        if(!z)
            printf("%c", pref[z]);
        else 
            printf(" %c", pref[z]);
    }
    printf("\n");
    i = 0; 
}

void printinfixa (char *s){
    int z; 
    for(z = 0; z<j; z++){
        if(!z)
            printf("%c", infi[z]);
        else 
            printf(" %c", infi[z]);
    }
    printf("\n");
    j = 0;
}

void printposfixa(char *s){
    int z; 
    for(z = 0; z<k; z++){
        if(!z)
            printf("%c", posf[z]);
        else 
            printf(" %c", posf[z]);
    }
    printf("\n");
    k = 0; 
}

int main () {
    int cont = 0; 
    char s[9], c; 
    ARV_BIN_BUSCA arv; 
    while(scanf("%s%*c", s)!=EOF){
        if(!strcmp(s, "I")){
            scanf("%c", &c);
            if(!cont){
                maketree(&arv, c);
                cont++;
            }
            else            
                ins_ele (&arv, c);            
        }
        else if(!strcmp(s, "PREFIXA"))
            prefixa(arv), printprefixa(pref);
        else if(!strcmp(s, "INFIXA"))
            infixa(arv), printinfixa(infi);
        else if(!strcmp(s, "POSFIXA"))
            posfixa(arv), printposfixa(posf);
        else{
            scanf("%c", &c);
            if(busca(arv, c))
                printf("%c existe\n", c);
            else 
                printf("%c nao existe\n", c);
        }

    }

}