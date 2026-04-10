#include <stdio.h>
#include <stdlib.h> 
#define LSB(a) (a & -a)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
int main() {
    int n; 
    while(scanf("%d", &n), n){
        long long v[n], a = 0, b = 0, c = 0; 
        for(int i = 0; i<n; i++){
            scanf("%lld", &v[i]); 
            a^=v[i]; 
        }
        
        for(int i = 0; i<n; i++){
            if(LSB(a) & v[i]) b^=v[i]; 
        }
        printf("%lld %lld\n", min(a^b, b), max (a^b, b));
        
        
    }
        
 
    return 0;
}