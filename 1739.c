#include <stdio.h>
#include <string.h>
#define fibo 1000
 
int main() {
    int n; 
    while(scanf("%d", &n)!=EOF){
        long long v[1000], t[60], i, cont = 0;
        v[0] = 0, v[1] = 1;
        for(i=2; i<fibo; i++)
            v[i] = v[i-2] + v[i-1];
        for(i=0; i<fibo; i++){
            char c [21], *p; 
            sprintf(c, "%lld", v[i]);
            p = strchr (c, '3');
            if(v[i]%3==0 || p)
                t[cont++] = v[i];
        }
        printf("%lld\n", t[n]);
    }
    
    
    
    
 
    return 0;
}