#include <stdio.h> 

int main () {
    char s[51];
    while(~scanf("%s", s)){
        int p, cr = 0, t = 0; 
        scanf("%d", &p);
        for(int i = 0; s[i]; i++){
            if(s[i] == 'R'){
                cr++; 
                if(cr == p) t++; 
            }
            else {
                if(cr) t+= 2; 
                else t++; 
            }
        }
    }
}