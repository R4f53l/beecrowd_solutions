#include <stdio.h> 
#include <ctype.h> 

int main () {
    char s[15]; 
    while(~scanf("%s", s)){
        int b1 = s[12] - '0', b2 = s[13] - '0';
        int sb1 = 0, sb2 = 0, i, c = 1, d = 9; 
        for(i=0; i<11; i++){
            if(isdigit(s[i])){
                sb1 += (s[i] - '0') * c++;
                sb2 += (s[i] - '0') * d--;
            }
        }
        
        if(sb1 % 11 == 0) sb1 = 0; 
        else sb1%=11; 
        if(sb2%11 == 0) sb2 = 0; 
        else sb2%=11; 

        if(sb1 == b1 && sb2 == b2) printf("CPF valido\n");
        else printf("CPF invalido\n");
       

    }
}