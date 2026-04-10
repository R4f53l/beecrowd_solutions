#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 


/*O que acontece aqui? 
Temos uma funcao que trabalha de forma recursiva. A ideia do merge sort é dividir e conquistar, isso significa que ele divide o vetor em subvetores, até que o mesmo seja apenas um elemento e depois sai ordenando
Então, qual a ideia? Utilizando a recursividade, definimos nosso criterio de parada sendo inicio < fim, vide que o meio sera constantemente atualizado. 
Quando fizermos isso, teremos todos os elementos devidamente separados e agora basta ordena-los utilizando a funcao merge. 
*/

void merge (int *v, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, fim1 = 0, fim2 = 0, i, j, k; 
    tamanho = fim - inicio + 1; 
    temp = (int*)malloc(sizeof(int)*tamanho);
    p1 = inicio; 
    p2 = meio + 1; 
    if(temp!=NULL){
        for(i = 0; i<tamanho; i++){
            if(!fim1 && !fim2){ //se meus vetores possuirem elemento, entao os comparo 
                if(v[p1] < v[p2])
                    temp[i] = v[p1++];
                else temp[i] = v[p2++];
                if(p1>meio) fim1 = 1; //se por um acaso meu vetor 1 tiver chegado ao fim
                if(p2>fim) fim2 = 1; //se meu vetor 2 tiver chegado ao fim
            }        
            else {
                if(fim1) 
                    temp[i] = v[p2++]; //atribuo para meu vetor auxiliar os elementos do vetor que ainda nao chegou ao fim
                else temp[i] = v[p1++];
            }        
        }
        for(j = 0, k = inicio; j<tamanho; j++, k++)
            v[k] = temp[j];    
    }
    free(temp);
}

void mergesort (int *v, int inicio, int fim){
    int meio; 
    if(inicio < fim){
        meio = floor((inicio + fim)/2);
        mergesort(v, inicio, meio);
        mergesort (v, meio+1, fim);
        merge(v, inicio, meio, fim);
    }
}

int main () {
    int v [] = {100, 3, 2, 582, 94, 32, 25, 583};
    mergesort(v, 0, 7);
    for(int i = 0; i<sizeof(v)/4; i++)
        printf("%d ", v[i]);
}