#include <stdio.h>
#include <stdlib.h> 
 
int main() {
    int n; 
    scanf("%d", &n);
    while(n--){
        int a, *v, c = 0;
        scanf("%d", &a);
        v = (int*)malloc(sizeof(int)*a);
        for(int i = 0; i<a; i++)
            scanf("%d", v+i);
        for(int i = 0; i<a-1; i++)
            if(v[i] < v[i+1])  
                c = (c+2) % a; 
        printf("%d\n", a-c);
    }
 
    return 0;
}