#include <stdio.h>
#include <math.h> 
#define pi 3.141592653597
 
int main() {
    double p, t, i, j; 
    int a, b, c; 
    while(~scanf("%d%d%d", &a, &b, &c)){
        p = (a+b+c)/2;
        t = sqrt(p * (p-a) * (p-b) * (p-c));
        i = pow(t/p, 2) * pi; 
        printf("%.4lf %.4lf %.4lf\n", pow(a*b*c/(4*t), 2)*pi-t, t-i, i);
    }
    
    
 
    return 0;
}