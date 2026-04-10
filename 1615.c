#include <stdio.h> 

int main () {
    int t; 
    scanf("%d", &t);
    while(t--){
        int n, i, a, ind, m; 
        float t; 
        scanf("%d%d", &n, &m);
        int v[1001] = {0};
        for(i=0; i<m; i++){
            scanf("%d", &a);
            v[a]++; 
        }
        int maior = 0;         
        for(i=1; i<=n; i++){            
            if(maior < v[i]){
                maior = v[i];
                ind = i; 
            }            
        }            
        t = (float) m/2.0; 
        if(v[ind] <= t) printf("-1\n");
        else printf("%d\n", ind);           

    }
}