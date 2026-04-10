#include <stdio.h> 
#include <math.h>
int main () {   
    float ma, mb, mc; 
    while(scanf("%f %f %f", &ma, &mb, &mc)!=EOF){
        float s = (ma+mb+mc)/2;            
        float r = s * (s-ma)*(s-mb)*(s-mc);           
        float a = (4 * sqrt(r))/3;
        if(a>0)
            printf("%.3lf\n", a);        
        else 
            printf("-1.000\n");
    }







    return 0;
}