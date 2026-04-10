#include <stdio.h> 
int main () {
    int i; 
    char s [100];
    while(scanf("%[^\n]", s)!=EOF){   
        getchar();
        for(i=0; s[i]; i++){    
            if(s[i]==',') break;    
            printf("%c", s[i]);
        }    
        i+=1; 
        printf("\n");
        for(i; s[i]; i++){
            printf("%c", s[i]);
        }
        printf("\n");
    }

}