#include <stdio.h>
#include <math.h> 
#define max 31
int main() {
    int t, i; 
    double v[max] = {0};
    v[0] = 1; 
    for(i=1; i<max; i++)
        v[i] += v[i-1] + pow(2, i);
    
    scanf("%d", &t);
    
    
    while(t--){
        int n;
        scanf("%d", &n);
        printf("%0.lf\n", v[n-1]);
    }
 
    return 0;
}