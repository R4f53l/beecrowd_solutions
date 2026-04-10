#include <stdio.h>
 
int main() {
    int n; 
    scanf("%d", &n);
    while(n--){
        int h, d, g, m = 1; 
        scanf("%d%d%d", &h, &d, &g);
        if(h<200 || h>300 && d<50 && g<150) m = 0;
        printf("%s\n", m ? "Sim":"Nao");
    }
    
    return 0;
}