#include <stdio.h>
#include <stdlib.h> 
 
int main() {
    int n; 
    scanf("%d", &n);
    while(n--){
        int a, c = 0; 
        scanf("%d", &a);
        int v[a]; 
        char s[a];
        for(int i = 0; i<a; i++)
            scanf("%d", v + i);
        scanf("%s", s);
        for(int i = 0; i<a; i++){
            if(s[i] == 'S' && (v[i] == 1 || v[i] == 2)) c++;
            else if(s[i] == 'J' && v[i] > 2) c++;  
        }
        printf("%d\n", c);
        
    }
   
    return 0;
}