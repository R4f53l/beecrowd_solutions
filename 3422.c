#include <stdio.h> 

int main () {
    int t; 
    scanf("%d", &t);
    while(t--){
        int a; 
        char s[3]; 
        scanf("%d%s", &a, s);
        if(s[0] == '1'){
            if(a > 45) 
                printf("45+%d\n", a - 45);  
            else printf("%d\n", a);          
        }
        else {
            if(a > 45) 
                printf("90+%d\n", a-45); 
            else printf("%d\n", a + 45);
        }    
    }
}