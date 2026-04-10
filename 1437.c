#include <stdio.h>
#define max 1000
int main() {
    int n; 
    while(scanf("%d", &n), n){
        int ct = 0;
        char s[max];
        scanf("%s", s);
        for(int j = 0; s[j]; j++){
            if(s[j] == 'D'){
                ct++; 
                if(ct == 4) ct = 0;
            } 
            else {
                ct--; 
                if(ct == -1) ct = 3;
            }
        }
        
        if(ct == 0) printf("N\n");
        else if(ct == 1) printf("L\n");
        else if(ct == 2) printf("S\n");
        else printf("O\n");
    }
    return 0;
}
 
  
