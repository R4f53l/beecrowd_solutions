#include <stdio.h> 
#include <ctype.h> 
#define max 2147483647

int main () {
    char s[101];
    double a; 
    while(~scanf(" %[^\n]", s)){
        char aux [101];
        int i, f = 0, neg = 0, cont = 0; 
        for(i=0; s[i]; i++){
            if(s[0] == '-'){
                neg = 1; 
                continue; 
            }
            if(isdigit(s[i])) aux[cont++] = s[i];
            else if(s[i] == 'O' || s[i] == 'o') aux[cont++] = '0';
            else if(s[i] == 'l') aux[cont++]= '1';            
            else if(s[i] == ' ' || s[i] == ',')                
                 continue;
            
            else f = 1; 
        }
        aux[cont] = 0; 
        sscanf(aux, "%lf", &a);        
        if(a>max || neg || f) printf("error\n");
        else printf("%lld\n", a);
        

    }
}