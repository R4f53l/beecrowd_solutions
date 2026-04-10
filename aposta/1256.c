#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n; 
    scanf("%d", &n);
    while(n--){
        int a, b; 
        scanf("%d%d", &a, &b);
        int *v = (int*) calloc (sizeof(int),  b+1);
        for(int i = 0; i<b; i++)
            scanf("%d", v+i);
        for(int i = 0; i<a; i++){
            printf("%d -> ", i);
            for(int j = 0; j<b; j++)
                if(v[j] % a == i)
                    printf("%d -> ", v[j]);
                 
            printf("\\\n");
        }
    }
 
    return 0;
}