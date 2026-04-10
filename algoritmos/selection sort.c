#include <stdio.h> 

/*Implementacao do selection sort: A ideia eh procurar o menor valor do vetor e trocar.*/

int main () {
    int v[] = {7, 5, 1, 8, 3}, ind, j; 
    for(int i = 0; i<(sizeof(v)/4) - 1; i++){
        int ind_menor = i; 
        for(j = i+1; j<sizeof(v)/4; j++)
            if(v[j] < v[ind_menor])
                ind_menor = j;
        if(v[ind_menor] < v[i]){
            int aux = v[i]; 
            v[i] = v[ind_menor];
            v[ind_menor] = aux; 
        }
    }
    for(int i = 0; i<sizeof(v)/4; i++)
        printf("%d ", v[i]);
}


//maneira alternativa: 

#include <stdio.h> 

void swap (int *a, int *b){
    int aux = *a; 
    *a = *b; 
    *b = aux;
}

void selection_sort (int *v, int size){
    int j; 
    for(int i = 0; i<size-1; i++){
        int ind_menor = i; 
        for(j = i+1; j<size; j++)
            if(v[j] < v[ind_menor])
                ind_menor = j; 
        if(i != ind_menor)
            swap(&v[ind_menor], &v[i]);
    }
}

int main () {
    int v[] = {7, 5, 1, 8, 3};    
    selection_sort(v, 5);    
    
    for(int i = 0; i<5; i++)
        printf("%d ", v[i]);
}
