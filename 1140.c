#include <stdio.h> 
#include <ctype.h> 
#include <stdbool.h>
int main () {
    char s[51], c, c1;     
    while(scanf("%s%c", s, &c)){     
        bool m = true;  
        char l = tolower(s[0]);        
        if(s[0]=='*') break;          
        if (c!='\n')
            while(scanf("%s%c", s, &c1)){
                char l2; 
                l2 = tolower(s[0]);
                if(l != l2)
                    m = false; 
                if(c1=='\n') break;
            }
        
        if(m)
            printf("Y\n");
        else   
            printf("N\n"); 
    }    
        return 0;
}
