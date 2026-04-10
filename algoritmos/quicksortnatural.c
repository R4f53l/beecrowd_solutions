#include <stdio.h>

void swap (int *a, int *b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int particiona (int *v, int inicio, int fim){
    int i = inicio, pivo = v[fim];
    for(int j = inicio; j<=fim-1; j++){
        if(v[j] <= pivo){
            swap(&v[j], &v[i]);
            i++; 
        }
    }
    swap(&v[fim], &v[i]);
    return i; 
}

void quicksort (int *v, int inicio, int fim){
    if(inicio < fim){
        int pivo = particiona (v, inicio, fim);
        quicksort (v, inicio, pivo-1);
        quicksort(v, pivo+1, fim);
    }
}
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    quicksort(arr, 0, 5);
    for(int i = 0; i<5; i++)
        printf("%d ", arr[i]);

    return 0;
}
