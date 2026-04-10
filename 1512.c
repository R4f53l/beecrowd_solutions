#include <stdio.h> 

long long gcd (int a, int b){
    long long i, menor, mdc; 
    menor = a<b? a:b;
    for(i=1; i<=menor; i++){
        if(a%i == 0 && b%i==0)
            mdc = i; 
    }
    return mdc; 
}

int main () {
    long long n, a, b; 
    while(scanf("%lld%lld%lld", &n, &a, &b), n, a, b){
        long long lsm = (a*b)/gcd(a,b), ans; 
        ans = (n/a) + (n/b) - (n/lsm);
        printf("%lld\n", ans);
    }
}