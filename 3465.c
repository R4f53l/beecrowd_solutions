#include <stdio.h>
#include <math.h> 
int main () {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double sp = (a+b+c)/2;
    double area = sqrt(sp*(sp-a)*(sp-b)*(sp-c));
    printf("%.3lf m2\n", area);
}