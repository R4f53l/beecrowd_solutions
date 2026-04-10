#include <stdio.h>

int main() {
    int ano, sec;
    while (scanf("%d", &ano) != EOF) {
        sec = ano / 100;
        if (ano % 100 != 0)
            sec++;
        printf("%d\n", sec);
    }
    
    return 0;
}