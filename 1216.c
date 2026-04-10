#include <stdio.h>
int main () {
    char s[100];
    int n, c = 0; 
    double soma = 0;   
    while(scanf("%[^\n]", s)!=EOF && scanf("%d\n", &n) != EOF){         
            c++; 
            soma+=n;         
    }    
    printf("%.1lf\n", soma/c);

}