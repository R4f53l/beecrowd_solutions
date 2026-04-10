#include <stdio.h> 
/*Qual a ideia do quicksort? 
- Definir um pivo, esse pivo sera "intocavel". A ideia eh colocar elementos menores a esquerda e
maiores a direita. Como fazer isso?
Bom, atribuimos para uma variavel esquerda o inicio, para a direita um final, para o pivo o primeiro 
elemento do nosso vetor 
O criteiro de parada eh o indice da esquerda ser maior do que o da direita
Dentro do while, havera a comparacao dos elementos que estao com indice da esquerda com o pivo, 
enquando esses elementos forem menores ou iguais que o pivo, devo incrementar o indice a esquerda

*/
int particiona (int *v, int inicio, int fim){
    int esq, dir, pivo, aux; 
    esq = inicio; 
    dir = fim; 
    pivo = v[inicio];
    while(esq < dir){
        while(v[esq] <= pivo && esq <= fim)
            esq++;
        while(v[dir] > pivo && dir>=0)
            dir--;
        if(esq < dir){
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux; 
        }
        v[inicio] = v[dir]; 
        v[dir] = pivo; 
        return dir; 
    }
}

void quicksort (int *v, int inicio, int fim){
    if(fim > inicio){
        int pivo = particiona (v, inicio, fim);
        quicksort (v, inicio, pivo-1);
        quicksort (v, pivo+1, fim);
    }
}

int main () {
    int v [] = {10, 2, 4, 5, 1};
    quicksort(v, 0, 4);
    for(int i = 0; i<5; i++)
        printf("%d ", v[i]);
}