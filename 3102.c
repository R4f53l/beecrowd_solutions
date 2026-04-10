#include <stdio.h> 




int main () {
    int n, x1, y1, x2, y2, x3, y3; 
    scanf("%d", &n);
    while(n--){
        float k; 
        scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
        k = (x1*y2 + y1*x3 + x2 * y3 - (y1*x2) - (x1*y3) - (y2*x3))/2;
        printf("%3.f", k);
    }

}