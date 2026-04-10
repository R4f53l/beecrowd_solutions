#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
int main() {
    long long a, b; 
    while(scanf("%lli %lli", &a, &b)!=EOF){        
        printf("%lli\n", abs(b-a));
    }
  
 
    return 0;
}