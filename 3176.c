#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct gnomo {
    char s[21];
    int d; 
};

int comp (const void *a, const void *b){         
    if (((*(struct gnomo*)b).d == (*(struct gnomo*)a).d))
        return strcmp((*(struct gnomo*)a).s, (*(struct gnomo*)b).s); 
    else return ((*(struct gnomo*)b).d) - ((*(struct gnomo*)a).d);     
}

int main () {
    struct gnomo v[30]; 
    int n, i, c = 1, a, c2 = 0; 
    scanf("%d", &n);
    for(i = 0; i<n; i++)
        scanf("%s%d", v[i].s, &v[i].d);
    
    qsort(v, n, sizeof(struct gnomo), comp);
    
    a = n/3;   
    while(1){
        printf("Time %d\n", c);
        for(i=0; i<3; i++)
            printf("%s %d\n", v[i*a + c2].s, v[i*a+c2].d);
        printf("\n");       
        c2++; 
        if(c == a) break;     
        c++;
    }
   
    
    

    
}