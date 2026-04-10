#include <stdio.h>


int main() {
    int s, va, vb; 
    while(~scanf("%d%d%d", &s, &va, &vb)){
         float t = s/(va-vb);
         if(t>0) printf("%.2f\n", t);
         else printf("impossivel\n");
         
         
         
    }
 
    
    
    return 0;
}