#include <stdio.h> 

int main () {
    int a = 0; 
    char s[100001];
    scanf("%s", s);
    for(int i = 0; s[i]; i++){
        if(s[i] != '(')
            continue;
        for(int j = i; s[j]; j++){
            if(s[j] == ')'){
                s[i] = 'X';
                s[j] = 'X';
                break; 
            }
        }
    }
    for(int i = 0; s[i]; i++)
        if(s[i] == '(') a++; 
    if(a) printf("Ainda temos %d assunto(s) pendente(s)!\n", a);
    else printf("Partiu RU!\n");
}