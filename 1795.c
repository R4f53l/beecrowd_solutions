#include <stdio.h> 
#include <math.h> 
#define max 21

int main() {
    int t, i; 
    double v[max] = {0};
    v[0] = 1; 
    for(i=1; i<max; i++)
        v[i] = pow(3, i);
    
    scanf("%d", &t);
    printf("%0.lf\n", v[t]);
    
 
    return 0;
}