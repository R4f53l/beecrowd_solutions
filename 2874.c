#include <stdio.h> 
#include <math.h> 
#include <string.h> 
#include <stdlib.h> 

int main () {
    char s[10], aux [10];
    int t, i, n;
    
    while(scanf("%d", &n) != EOF){
        int cont = 0, v[100001];
        while(n--){
            scanf("%s", s);
    
            for(i=0; s[i]; i++)
                aux[i] = s[strlen(s)-i-1];
    
            for(i=0; aux[i]; i++){
                if (aux[i] == '1'){
                    t+= pow(2, i);
                }
            }
            
            printf ("%d", t);
            
            v[cont++] = t; 
            t = 0; 
        }
        for(i=0; i<cont; i++)
            printf("%c", v[i]);
        printf ("\n");
    
    }
    
    
    
}