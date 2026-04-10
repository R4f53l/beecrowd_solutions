#include <stdio.h> 
#include <string.h> 
#define max 26

int main () {
    int n; 
    while(scanf("%d", &n), n){
        char c, s[max];
        int d, co[max] = {0}, in[max] = {0}, soma = 0, total = 0; 
        for(int i = 0; i<n; i++){
            scanf(" %c%d%s", &c, &d, s);             
            if(!strcmp(s, "correct") && !co[(int)c - 65])
                co[(int)c - 65] = d;  
            else if (!strcmp(s, "incorrect") && !co[(int)c - 65])
                in[(int)c - 65] += 20;                       
        }        
        for(int i = 0; i<max; i++){
            if(co[i]){
                total++;
                soma += (co[i] + in[i]);
            }
        }
            
        printf("%d %d\n", total, soma);
         
    }
}