#include <stdio.h>
#include <math.h>


int eh_primo (long long n){
    
    if(n==1) return 1; 
    else {
        int i, r = sqrt(n);
        for(i=2; i<=r; i++){
            if((n%i)==0) return 0; 
        }        
    }
    return 1; 
    
}

int main () {
    long long n; 
    scanf("%lld", &n);    
    if(eh_primo(n)) printf("N\n");
    else printf("S\n");
    
    

}