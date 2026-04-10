#include <stdio.h>
 
int main() {
    long long a, b, c, s; 
    char o; 
    scanf("%lld %lld %lld %c", &a, &b, &c, &o);
    if(o == 'A')
        s =  a + b*3.0/2 + c*5.0/2; // 1 + 3 + 7 = 11
    else if(o == 'B')
        s =  b + 2.0*a/3 + 5.0*c/3;
    else
        s =  c + 2.0*a/5  + 3.0*b/5; //0 4 2 -> 2 + (0) + (3/5) * 4 -> 2 + 2.4 = 4.4
    printf("%lld\n", s);
        
    
    

 
    return 0;
}