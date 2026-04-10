#include <stdio.h> 
#define max 10000

int main () {
    int n, c, v[max];    
    scanf("%d%d", &n, &c);
    
    for(int i = 0; i<n; i++)
        scanf("%d", v+i);
        
    while(c--){
        int a, b, c, d, s = 0; 
        scanf("%d", &a);
        a ? scanf("%d%d", &b, &c) : scanf("%d%d%d", &b, &c, &d);

        if(a) {
            for(int i = b-1; i<c; i++)
                s += v[i];
            printf("%d\n", s);
        }
        
        else 
            for(int i = b-1; i<c; i++)
                v[i] += d;         
    }
    
}