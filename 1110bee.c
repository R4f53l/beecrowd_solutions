/*QUESTAO 1110 BeeCrowd*/
/*Enunciado: 
Dada uma pilha de n cartas enumeradas de 1 até n com a carta 1 no topo e a carta n na base. A seguinte operação é ralizada enquanto tiver 2 ou mais cartas na pilha. 
Jogue fora a carta do topo e mova a próxima carta (a que ficou no topo) para a base da pilha. Sua tarefa é encontrar a sequência de cartas descartadas e a última carta remanescente.Cada linha de entrada 
(com exceção da última) contém um número n ≤ 50. A última linha contém 0 e não deve ser processada. Cada número de entrada produz duas linhas de saída. 
A primeira linha apresenta a sequência de cartas descartadas e a segunda linha apresenta a carta remanescente*/
#include <stdio.h> 
#include <stdlib.h> 
#define max 51 
typedef struct {
    int n; 
    int inicio; 
    int fim; 
    int val[max];
}FILA_SEQ;
void cria_fila(FILA_SEQ *f){
    f->n = 0; 
    f->inicio = 0; 
    f->fim = -1;
}

int tam (FILA_SEQ *f){
    return (f->n);
}

void ins (FILA_SEQ *f, int v){    
    if(f->n == max-1){
        printf("Erro! Nao ha mais espaco!\n");
        exit(1);
    }
    f->fim = (f->fim+1)%max;  
    f->val[f->fim] = v; 
    f->n++;
}

int cons (FILA_SEQ *f){
    if(!f->n){
        printf("Erro! A fila eh vazia!\n");
        exit(2);
    }
    return f->val[f->inicio];
}

void ret (FILA_SEQ *f){
    if(!f->n){
        printf("Erro! A fila eh vazia!\n");
        exit(3);
    }
    f->inicio = (f->inicio+1)%max; 
    f->n--;
}


int main () {
    int a, x;
    while(scanf("%d", &a), a){ 
        FILA_SEQ f; 
        cria_fila(&f);
        for(int i=1; i<=a; i++){
            ins(&f, i);
        }
        printf("Discarded cards:"); //1 3 5 4
        while(tam(&f)>1){ //f.n
            printf(" %d", cons(&f));
            if(tam(&f)>2) //f.n
                printf(",");
            ret(&f);
            x = cons(&f);
            ret(&f);
            ins(&f, x);
        }
        printf("\n");
        printf("Remaining card: %d\n", cons(&f)); //2
    }
}