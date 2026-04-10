#include <stdio.h> 
#include <math.h> 
#define n 101
int main () {
    double v[n] = {0, 1};   
    long long a = 0;   
    char s[10001];
    for(int i = 2; i<n; i++)
        v[i] = v[i-1] + v[i-2];
    /*Numeros binarios e fibonacci*/
    scanf("%s", s);
    for(int i = 0; s[i]; i++)
        if(s[i] == '1') a += pow (i+1, 2);

    printf("%.0lf\n", v[a-1]);  
        
    
    
}