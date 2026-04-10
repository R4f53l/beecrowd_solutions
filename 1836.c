#include <stdio.h> 
#include <math.h> 
#define n 4
int main () {
    int t, c = 1; 
    scanf("%d", &t);
    while(t--){
        char nome [21];
        int l, bs, iv, v[n];
        float ev; 
        scanf("%s %d", nome, &l);
        for(int i = 0; i<n; i++){
            scanf("%d%d%f", &bs, &iv, &ev);
            if(!i) v[i] = (int)((((iv + bs + sqrt(ev)/8. + 50) * l) / 50) + 10); 
            else v[i] = (int)((((iv + bs + sqrt(ev)/8.) * l) / 50) + 5);
        }
        printf("Caso #%d: %s nivel %d\n", c++, nome, l);
        printf("HP: %d\n", v[0]);
        printf("AT: %d\n", v[1]);
        printf("DF: %d\n", v[2]);
        printf("SP: %d\n", v[3]);

    }
}