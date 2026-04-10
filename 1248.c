#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#define max 28

int comp (void const *a, void const *b){
    return *(char*)a - *(char*)b;
}

int main() {
    int n; 
    scanf("%d ", &n);
    while(n--){
        int cont = 0, p = 0;
        char s [max], s2[max], s3[max], aux[max];
        fgets(s, max, stdin), fgets(s2, max, stdin), fgets(s3, max, stdin);
        strcat (s2, s3);
        for(int j = 0; s2[j]; j++){
            if(!strchr (s, s2[j])){
                p = 1;
                break;            
            }
        }    
        for(int i = 0; s[i]; i++){
            int t = 0;
            for(int j = 0; s2[j]; j++)
                if(s[i] == s2[j])
                    t = 1; 
            if(!t) aux[cont++] = s[i];
        }
        aux[cont] = 0;
        if(p) printf("CHEATER\n");
        else { 
            qsort(aux, cont, sizeof(char), comp);
            printf("%s\n", aux);
        }
        
        
    }
    return 0;
}