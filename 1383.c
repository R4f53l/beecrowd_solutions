#include <stdio.h> 

#define MAX 10

int main(){
    int n, cont = 1; scanf("%d", &n); 
    while(n--){
        int l[MAX] = {}, c[MAX] = {}, b[MAX] = {}, possible = 1; 

        for(int i = 0; i < MAX - 1; i++){
            for(int j = 0; j < MAX - 1; j++){
                int a; scanf("%d", &a); 
                if(l[i] & (1 << a) || c[j] & (1 << a) || b[(i / 3) * 3 + j / 3] & (1 << a))
                    possible = 0;
                l[i] |= (1 << a); 
                c[j] |= (1 << a); 
                b[(i / 3) * 3 + j / 3] |= (1 << a); 
            }
        }
        printf("Instancia %d\n", cont++); 
        printf("%s\n\n", possible ? "SIM" : "NAO");
        
    }
}