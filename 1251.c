#include <stdio.h>
#include <stdlib.h> 

struct vasco {
    int ta; 
    int q; 
};
 
int comp (void const *a, void const *b){
    struct vasco x = *(struct vasco*)a, y = *(struct vasco*)b;
    if(x.q == y.q){
        return y.ta - x.ta;
    }
    return x.q - y.q; 
} 

int main() {
    char s [1001];
    while(~scanf("%s", s)){
        int cont = 32; 
        struct vasco v[130] = {};
        for(int i = 0; s[i]; i++){
            v[(int) s[i]].ta = (int) s[i];
            v[(int) s[i]].q++; 
        }
        qsort(v, 130, sizeof(struct vasco), comp);
        for(int i = 0; i < 130; i++)
            if(v[i].q) printf("%d %d\n", v[i].ta, v[i].q);
        
    }
    
 
    return 0;
}