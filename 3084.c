#include <stdio.h>
#include <math.h>
 
int main() {
    int h, m; 
    while(scanf("%d %d", &h, &m)!=EOF){
        int hf = h/30;
        int mf = m/6; 
        printf("%02d:%02d\n", hf, mf);
    }
 
    return 0;
}