#include <stdio.h>
#include <math.h> 
#define m 1.25506
 
int main() {
    int n; 
    scanf("%d", &n);
    printf("%.1f %.1f\n", n/log(n), (n/log(n))*m);
 
    return 0;
}