#include <stdio.h> 
#include <string.h> 

typedef struct {
    char s [11]; 
    int n; 
}Ass; 

void clear (Ass *a){
    int i; 
    for(i=0; i<100; i++)
        a[i].n = 0;  
}

int main () {
    int cont = 0, i; 
    Ass a[100];
    char m[100][11], as[11], mrt[11];    
    clear(a);
    while(scanf("%s%s", as, mrt)!=EOF){
        strcpy (a[cont].s, as);
        strcpy (m[cont], mrt);
        cont++;
        for(i=0; i<cont; i++)
            if(!strcmp(a[i].s, as)){ a[i].n++; break;} 
        for(i=0; i<cont; i++)
            printf("%s\n%d\n", a[i].s, a[i].n);
    }


}