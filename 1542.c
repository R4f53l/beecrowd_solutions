#include <stdio.h>
 
int main() {
    int a, b, c; 
    while(scanf("%d%d%d", &a, &b, &c), a){
        int r; 
        r = (int) (a*b*c)/(c-a);
        if(r <= 1) printf("%d pagina\n", r);
        else printf("%d paginas\n", r);
    }
   
 
    return 0;
}