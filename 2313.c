#include <stdio.h>
#include <math.h>
 
int main() {
    int a, b, c; 
    scanf("%d%d%d", &a, &b, &c);
    if(a + b > c && b + c > a && c + a > b){
        printf("Valido-");
        if(a == b && b == c)
           printf("Equilatero\n");
        else if(a == b || b == c || c == a)
            printf("Isoceles\n");
        else 
            printf("Escaleno\n");
        printf("Retangulo:");
        if(pow(a, 2) == pow(b, 2) + pow(c, 2) || pow(b, 2) == pow(c, 2) + pow(a, 2) || pow(c, 2) == pow(b, 2) + pow(a, 2))
            printf("S\n");
        else printf("N\n");
    }
    else 
        printf("Invalido\n");
    return 0;
}