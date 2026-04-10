#include <stdio.h> 
#include <string.h> 
#define max 100001

int main () {
    char s[max];    
    while(~scanf("%s", s)){
        char str[max];
        int c = 0;
        for(int i = strlen(s); i>=0; i--){
            if(s[i] == '['){
                for(int j = i+1; s[j] && s[j] != ']' && s[j] != '['; j++)
                    str[c++] = s[j];
            }
        }
        int p = 0; 
        for(int i = 0; s[i]; i++){            
            if(s[i] == '[') p = 1; 
            else if(s[i] == ']') p = 0;
            else if(!p) str[c++] = s[i]; 
        }
        str[c] = 0;
        printf("%s\n", str);
    }
}