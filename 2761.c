#include <stdio.h>
int main () {
    int a; 
    float b; 
    char c; 
    char s[51];
    scanf("%d %f %c %[^\n]", &a, &b, &c, s);
    printf("%d%f%c%s\n", a, b, c, s);
    printf("%d\t%f\t%c\t%s\n", a, b, c, s);
    printf("%10d%10f%10c%10s\n", a, b, c, s);

}