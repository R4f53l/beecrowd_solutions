#include <stdio.h>
 
int main() {
    char s[100001];
    int n, i = 0, cont = 0, qntd = 0, j;
    scanf("%d", &n);
    scanf("%s", s);
    for(j=0; j<n; j++){
        while(s[i++] == 'a'){
            cont++;
            j++;
        }
        if(cont > 1)
            qntd+= cont; 
        cont = 0;
    }
    printf("%d\n", qntd);
 
    return 0;
}