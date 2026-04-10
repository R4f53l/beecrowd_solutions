#include <stdio.h>
 
int main() {
    int n; 
    char str[21];
    float porcs = 0, porca = 0, porcb = 0;
    scanf("%d", &n);
    while(n--){
        int e1, e2, e3, s, b, a;
        scanf("%d%d%d", &e1, &e2, &e3);
        scanf("%d%d%d", &s, &b, &a);
        printf("%d\n", n);
        porcs += (s/e1)*100.0;
        porcb += (b/e2)*100.0;
        porca += (a/e3)*100.0;
    }
    printf("Pontos de Saque: %.2f %%\n", porcs);
    printf("Pontos de Bloqueio: %.2f %%\n", porcb);
    printf("Pontos de Ataque: %.2f %%\n", porca);
 
    return 0;
}