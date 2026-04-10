#include <stdio.h> 
#include <string.h> 

int main () {
    int n;
    char s[] = "abcdefghijklmnopqrstuvxwyz", t[101];
    while(~scanf("%d", &n)){
        while(n--){
            int i, c = 0, ce = 0; 
            scanf(" %[^\n]", t);
            for(i=0; t[i]; i++){
                if(t[i] == ' ')
                    ce++;                              
            }
            for(i=0; t[i]; i++){
                if(t[i] == '.') c++;
                else break;                                                
            }            
            printf("%c\n", s[(c-1) + 3*ce]);
        }
    }


}