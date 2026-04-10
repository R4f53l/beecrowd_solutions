#include <stdio.h> 
#include <string.h> 

const int MAX = 1e5 + 10;


int main (){
    int t; scanf("%d", &t);
    while(t--){
        int n, c; scanf("%d%d", &n, &c);
        long long a[MAX];
        memset(a, 0, sizeof a);
        for(int i = 0; i<c; i++){
            int b, p, q, v; 
            scanf("%d", &b); 
             
            
            if(!b){
                scanf("%d%d%d", &p, &q, &v);
                for(int i = p; i<=q; i++)
                    a[i] += v; 
            }
            else {
                scanf("%d%d", &p, &q);
                long long s = 0; 
                for(int i = p; i<=q; i++)
                    s += a[i];
                printf("%lld\n", s);
            }
        
        }
        
    }
    
}