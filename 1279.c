#include <stdio.h> 
#include <string.h>
#include <stdbool.h>
int main () {
    char s[1002];
    int n, i, first = 1;
    while(scanf("%s", s)!=EOF){
        int m4 = 0, m15 = 0, m55 = 0, m100 = 0, m400 = 0; 
        if(!first){
            printf("\n");
        }           
        first = 0;   
        bool a = false, b = false;         
        int len = strlen(s);
        for(i=0; i<len; ++i){
            m4 = ((m4*10) + (s[i] - '0')) % 4; 
            m15 = ((m15*10) + (s[i] - '0')) % 15; 
            m55 = ((m55*10) + (s[i] - '0')) % 55; 
            m100 = ((m100*10)+(s[i] - '0')) % 100;
            m400 = ((m400*10) + (s[i] - '0')) % 400;   
                
        }
        /*printf("%d\n", m4);
        printf("%d\n", m15);
        printf("%d\n", m55);
        printf("%d\n", m100);
        printf("%d\n", m400);*/
        

        if((!m4) && m100){
            printf("This is leap year.\n");
            a = true; 
        }    
        
        if((!m400) && (!m100)){
            printf("This is leap year.\n");   
            a = true;          
        }         
        if(!m15){
            printf("This is huluculu festival year.\n");     
            b = true;       
        }        
        if((!m55) && a){
            printf("This is bulukulu festival year.\n");
            b = true;              
        }
        if(!a && !b){
            printf("This is an ordinary year.\n");
        }        
            
        
        
    }






    return 0;
}