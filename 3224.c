#include <stdio.h> 
#include <string.h> 
int main () {
    char j[1000], m[1000];
    scanf("%s %s", j, m);
    if(strlen(j)<strlen(m))
        printf("no\n");
    else 
        printf("go\n");
}