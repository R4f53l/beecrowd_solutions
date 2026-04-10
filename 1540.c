#include <stdio.h>
#include <math.h> 
#include <locale.h>

int main() {
   
    int n; 
    scanf("%d", &n);
    while(n--){
        int a, c, i; 
        double b, d; 
        scanf("%d%lf%d%lf", &a, &b, &c, &d);
        c = c-a; 
        d = d-b; 
        d = d/c; 
        i = d; 
        b = trunc((d-i)*100);         
        printf("%d,%02.lf\n", i, b);
    }
    
 
    return 0;
}