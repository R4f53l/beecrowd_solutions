#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
 
int main() {
    int i;
    char s[100]; 
    while(scanf("%[^\n]", s)!=EOF){
        getchar();
        bool masc = false, min = false, dig = false, si = false;
        int size = strlen(s);
        for(i=0; s[i]; i++){
            if(s[i]>='A' && s[i]<='Z')
                masc = true;
            if(s[i]>='a' && s[i] <='z')
                min = true; 
            if(isdigit(s[i]))
                dig = true; 
            if(s[i]>=32 && s[i]<=47 || s[i] >=58 && s[i]<=64 || s[i]>=91  && s[i]<=96 || s[i]>=123 && s[i]<=126)
                si = true; 
            
        }
        if(!masc || !min || !dig || size<6 || size>32)
            si = true;
        if(masc){
            if(min){
                if(dig){
                    if(!si){
                            printf("Senha valida.\n");
                    }
                        
                }
            }
        }
        
        if(si)
            printf("Senha invalida.\n");
       
    }
    
 
    return 0;
}