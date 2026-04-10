#include <stdio.h> 

#define MAX 21

typedef struct nome {
    char s [MAX];
}nome; 

int main (){
    int n; 
    float l, q; 
    scanf("%d%f%f", &n, &l, &q);
    int i = 0, d =  l * 10, c = 0; 
    nome v[n];
    for(int j = 0; j<n; j++)
        scanf(" %s", v[j].s);
    
    for(; i + q*10 < d; i += q * 10, c++);
    
    
    printf("%s %.1f\n", v[c%n].s, (d - i)/10.0);
    
}