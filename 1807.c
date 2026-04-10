#include <stdio.h> 
#define mod 2147483647

long long potencia (int a, int b){
    if(b==0)
        return 1; 
    long long x = potencia (a, b/2);
    if(b%2)
        return (long long) x * x % mod * a % mod;
    return (long long) x * x % mod; 
}

int main () {
    long long n; 
    scanf("%lld", &n);
    printf("%lld\n", pow(n, 3) % mod);
    return 0; 
}