#include <stdio.h>
#define max 100000
int main() {
    long long v [max], n, i; 
    v[0] = 1; 
    v[1] = 1; 
    /*2 = 2, 3 = 3, 4 = 5*/
    scanf("%d", &n);
    for (i = 2; i<=n+2; i++)
        v[i] = v[i-1] + v[i-2];
    printf("%lld\n", v[i-1]+1);
        
        
 
    return 0;
}