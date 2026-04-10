#include <stdio.h>

int main() {
    int v[max], i; 

    for(i=0; i<max; i++)
        scanf("%d", v+i);
    
    if(v[0] > v[1] && v[1] > v[2] && v[2] > v[3] && v[3] > v[4]) printf("D\n");
    else if(v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4]) printf("C\n");
    else printf("N\n");
    
    return 0;
}