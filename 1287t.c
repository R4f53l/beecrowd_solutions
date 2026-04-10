#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#define max 2147483647

int main () {
    char s[52];
    double a; 
    while(fgets(s, 52, stdin)!=NULL){
        char aux [52];
        int i, f = 0, neg = 0, cont = 0, tam;
        tam = strlen(s);
        
        if(s[0] == '\n')
            f = 1; 
        
        for(i=0; i<tam-1; i++){
            if(s[0] == '-'){
                neg = 1; 
                continue; 
            }
            if(isdigit(s[i])) aux[cont++] = s[i];
            else if(s[i] == 'O' || s[i] == 'o') aux[cont++] = '0';
            else if(s[i] == 'l') aux[cont++]= '1';            
            else if(s[i] == ' ' || s[i] == ',') continue;
            else f = 1; 
        }
        aux[cont] = 0; 
        if(!f){
            sscanf(aux, "%lf", &a); 
            if(a>max || neg) printf("error\n");
            else printf("%.0lf\n", a);
        }
        else printf("error\n");
        
        

    }
}