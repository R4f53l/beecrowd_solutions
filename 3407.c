#include <stdio.h>
 
int main() {
    int n, m, qn, qs, pn = 0, ps = 0, aux;
    scanf("%d %d", &n, &m);
    aux = n;
    while(n--){
        scanf("%d", &qn);
        if(qn)
            pn++;
    }
    while(aux--){
        scanf("%d", &qs);
        if(qs)
            ps++;
    }
    if(pn == m)
        printf("Tudo certo.\n");
    else if(pn != m && ps == m)
        printf("Pegou de Samuel.\n");
    else 
        printf("Pegou de um estranho.\n");
    
    
    return 0;
}