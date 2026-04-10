#include <stdio.h> 

int main () {
    int a = 9, b = 36, resto;

    do {
        resto = a % b; 
        a = b; 
        b = resto;
    }while(resto);
    
    printf("%d\n", a);
}