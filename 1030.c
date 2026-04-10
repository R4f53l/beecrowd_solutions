#include <stdio.h>

int jose (int n, int b){
    int i, x = 0; 
    for(i=1; i<=n; i++){
        x = (x+b)%i;
    }
    return x; 
} 
 
int main() {
    int n, c = 1; 
    scanf("%d", &n);
    while(n--){
        int a, b; 
        scanf("%d%d", &a, &b);
        printf("Case %d: %d\n", c++, jose(a, b)+1);
    }
    
 
    return 0;
}