#include <stdio.h>
#define max 10
 
int main() {
    int n, i, j, b = 1, m[max][max], v[max] = {0};
    scanf("%d", &n);    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            scanf("%d", &m[i][j]);
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            v[i] += m[i][j];
    }
    for(i=0; i<n-1; i++){
        if(v[i] != v[i+1]){
            b = 0; 
            break;
        }
    }
    if(!b) printf("-1\n");
    else printf("%d\n", v[0]);
    
 
    return 0;
}