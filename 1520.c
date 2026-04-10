#include <stdio.h> 
#include <stdlib.h> 

int ord (const void *a, const void *b){
    return *(int*) a - *(int*)b; 
}

int main () {
    int n, x, y, j; 
    while(~scanf("%d", &n)){
        int v[101], p = 0, i = 0, a; 
        while(n--){
            scanf("%d%d", &x, &y);         

            for(;x<=y; x++)
                v[i++] = x; 
        }
        qsort(v, i, sizeof(int), ord);        
        scanf("%d", &a);
        for(j=0; j<i; j++){
            if(v[j] == a) x = j, p++;      
        }
        printf("%d\n",  p);
        if(p) printf("%d found from %d to %d\n", a,  (x-p)+1, x);
        else printf("%d not found\n", a);        

    }
}