#include <stdio.h> 
int main () {
    unsigned a, b; 
    while(1){
        int c = 0, r = 0, cont = 0;
        scanf("%u %u", &a, &b);
        if(a==0 && b==0) break;
        for(;a||b; a/=10, b/=10){
            c += a%10+b%10;
            if(c>9){cont++; c=1;}
            else c = 0;
        }                
        if(cont>1)
            printf("%d carry operations.\n", cont);
        else if(cont)
            printf("%d carry operation.\n", cont);
        else 
            printf("No carry operation.\n");
    }
}