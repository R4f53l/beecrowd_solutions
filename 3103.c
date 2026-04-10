#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 1001

int cmp(const void *a, const void *b){
    return *(char *)a - *(char *)b;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int i, ind, menor = 10; 
        char n[max];
        scanf(" %s", n);
        qsort(n, strlen(n), sizeof(char), cmp);
        
        if(n[0] == '0'){
            for(int i = 0; n[i]; i++){
                if(n[i] != '0'){
                    char aux = n[i];
                    n[i] = n[0];
                    n[0] = aux;
                    break;
                }
            }
        }
        for(int i = 0; n[i]; i++)
            printf("%c", n[i]);
        
        printf("\n");
        
    }
}