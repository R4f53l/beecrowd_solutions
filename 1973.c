#include <stdio.h> 
#include <stdlib.h>


int main () {
    int n, i, *v, c = 0, ne = 0;
    v = (int*) malloc (sizeof(int));
    for(i=0; i<n; i++)
        scanf("%d", v+i);
    i = 0; 
    while(v[i]){
        printf("oi\n");
        c++;
        if(v[i]%2){
            i = (i+1)%n;
            v[i]--; 
        }
        else {
            i--;
            if(i<0) break;
            v[i]--;
        }
    }
    for(i = 0; i<n; i++)
        ne += v[i];
    printf("%d %d\n", c, ne);
}