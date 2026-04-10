#include <stdio.h> 
int main () {
    int n, f, somab = 0, somaa = 0, somam = 0, somad = 0;
    scanf("%d", &n);
    while(n--){
        int a;
        char s[100], s2[100];
        scanf("%s %s %d", s, s2, &a);
        if(s2[0]=='b')
            somab += a; 
        if(s2[0]=='a')
            somaa += a; 
        if(s2[0]=='m')
            somam += a; 
        if(s2[0]=='d')
            somad += a;
    }
    f = somab/8 + somaa/4 + somam/6 + somad/12;  
    printf("%d\n", f);





    return 0;
}