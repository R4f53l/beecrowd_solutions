#include <stdio.h>
#define n 12
int main() {
    int v [] = {90, 3, 2, 8, 27, 84, 102, 3782, 328, 321, 234, 455}, i, j;
    
    for(i=0; i<n-1; i++){
        for(j = 0; j<n-i-1; j++){
            if(v[j] > v[j+1]){
                int aux = v[j]; 
                v[j] = v[j+1]; 
                v[j+1] = aux; 
            }
        }
    }
    for(i=0; i<n; i++)
        printf("%d ", v[i]);
    

    return 0;
}
