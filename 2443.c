#include <stdio.h>
 
int main() {
    int a, b, c, d, maior, menor, num, den;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    num = a*d + b*c; 
    den = b * d; 
    maior = num > den? num: den;
    menor = num< den? num:den;
    while(menor){
        int r = maior%menor;
        maior = menor; 
        menor = r; 
    }
    printf("%d %d\n", num/maior, den/maior);
    return 0;
}