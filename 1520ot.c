#include <stdio.h> 
#include <stdlib.h> 



int main () {
    int n, x, y; 
    while(~scanf("%d", &n)){
        int v[101] = {0}, c = 0, i, a; 
        while(n--){
            scanf("%d%d", &x, &y);         

            for(;x<=y; x++)
                v[x]++;
        }        ;        
        scanf("%d", &a);
        if(v[a]){
            for(i=1; i<a; i++) c+=v[i]; 
            printf("%d found from %d to %d\n", a, c, (c+v[i])-1);
        }         
        else printf("%d not found\n", a);        

    }
}