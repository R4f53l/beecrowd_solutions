#include <stdio.h> 
#include <math.h> 

int eh_primo (int n){
    int i; 
    if(n < 2)
        return 0; 
    for(i=2; i<=sqrt(n); i++){
        if(n%i == 0 && n!=i) 
            return 0;
    }
    return 1; 
}

int main () {
    int n, i, p1, p2; 
    scanf("%d", &n);
    if(!(n%2)) n--; 
    for(i=n; i>=5; i-=2){
        if(eh_primo(i-2)){
            if(eh_primo(i)){
                p1 = i-2; 
                p2 = i; 
                break;
            }
        }
    }
    printf("%d %d\n", p1, p2);

}