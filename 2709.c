#include <stdio.h>
#include <math.h> 
int eh_primo (int a){
    int i, c; 
    if(a==0 || a == 1)
        return 0;
    else{
        c = sqrt(a);
        for(i=2; i<=c; i++){
            if(%i==0)
                return 0;
        }
    }
    return 1;   
} 

int main (){
    int m, v, n;         
    while(scanf("%d", &m)!=EOF){
        int ve[m], i, soma = 0;
        for(i=0; i<m; i++){
            scanf("%d", &n);
            ve[i]  = n;        
        }        
        scanf("%d", &v);
        for(i=m-1; i>=0; i-=v)  
            soma += ve[i];        
        if(eh_primo(soma))
            printf("You’re a coastal aircraft, Robbie, a large silver aircraft.\n");
        else 
            printf("Bad boy! I’ll hit you.\n");      
        
    }
    return 0;
}