#include <stdio.h>
#include <math.h> 
#include <stdbool.h> 
#define max 100000
#define dist 60000000
 
int main() {
    int n, v[max], i, j, cont = 0, q; 
    v[0] = 2;
    for(i=3; i<max; i+=2){
        bool m = false; 
        int r = sqrt(i); 
        for(j=0; j<sizeof(v)/4; j++){
            if(v[j]>r) break;
            if(i%v[j]==0){
                m = true; 
                break; 
            }
        }
        if(!m) v[cont++] = i; 
    }
    int a, c = 0, soma = 0; 
    scanf("%d", &a);
    for(int i = 0; c < 10; i++) {
        if(v[i] >= a){
            soma += v[i]; 
            c++;
        } 
    }
    printf("%d km/h\n%d h / %d d\n", soma, (int) dist/soma, (int) (dist/soma) / 24);
    
    return 0;
}