#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#define MAX 110

int main() {
    int n, k, v[MAX] = {};
    while(scanf("%d%d", &n, &k), n){
        memset(v, 0, sizeof(v));
        for(int i = 0; i<n; i++){
            int a; scanf("%d", &a); 
            v[a]++; 
        }
        int c = 0; 
        for(int i = 0; i<MAX; i++){
            if(v[i] >= k) c++;
        }
        printf("%d\n", c);
    }
    
    
 
    return 0;
}