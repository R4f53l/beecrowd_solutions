#include <stdio.h> 
int main() {
    int n; 
    while(scanf("%d", &n)!=EOF){  
        //LIFE IS NOT A PROBLEM TO BE SOLVED
        char s [] = "LIFE IS NOT A PROBLEM TO BE SOLVED";
        for(int i=0; i<n; i++)
            printf("%c", s[i]);
        printf("\n");
    }
 
    return 0;
}