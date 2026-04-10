#include <stdio.h> 
#include <math.h> 
#define pi 3.14159
#define g -9.80665
double quadratic (double a, double b, double c){
    double delta = pow(b, 2)-4*a*c;
    double rp = (-b + sqrt(delta))/(2*a);
    double rn = (-b - sqrt(delta))/(2*a); 
    return rp > 0? rp: rn;
}
double rad (double a){
    return (a/180)*pi;
}
int main () {
    double h; 
    while(scanf("%lf", &h)!=EOF){
        int i, f, t; 
        scanf("%d %d %d", &i, &f, &t);
        while(t--){
            double v, a; 
            scanf("%lf %lf", &a, &v);
            double vx = v*cos(rad(a));            
            double vy = v*sin(rad(a));                        
            double dis = vx * quadratic(g/2, vy, h);
            if(dis>=i && dis<=f)
                printf("%.5lf -> DUCK\n", dis);
            else 
                printf("%.5lf -> NUCK\n", dis);
        }
        
    }






    return 0; 
}