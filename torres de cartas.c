#include <stdio.h> 

int main () {
    int t;
    scanf("%d", &t);
    while(t--){
        int mi = 1, ma = 1000000001;         
        long long c, q;
        scanf("%lld", &c);
        while(mi+1 != ma){            
            long long a = (mi + ma)/2; 
            q = (3*a + 1)*a / 2;
            if(q > c)
                ma = a; 
            else if(q == c){
                mi = a; 
                break;
            }
            else 
                mi = a; 
        }
        printf("%d\n", mi);
    }
}