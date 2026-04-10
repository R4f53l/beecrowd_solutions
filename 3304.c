#include <stdio.h>
 
int main() {
    int n; 
    
    while(~scanf("%d", &n)){
        int s = 1, q = 0; 
        if(n % 4 == 0 || n % 7 == 0)
            q = 1; 
        while(n){
            int a = n%10; 
            n /= 10; 
            if(a != 4 && a != 7)
                s = 0; 
        }
        if(s) printf("sortudo\n");
        else if(q) printf("quase sortudo\n");
        else printf("azarado\n");
    }
    
 
    return 0;
}