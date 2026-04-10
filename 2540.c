#include <stdio.h>
 
int main() {
    int n, i; 
    while(scanf("%d", &n)!=EOF){
        int c = 0, a;               
        for(i=0; i<n; i++){
            scanf("%d", &a);
            if(a)   
                c++; 
        }
        float v = (2.0/3) * n;
        if(c>=v)
            printf("impeachment\n");
        else
            printf("acusacao arquivada\n");
                
        
    }
 
    return 0;
}