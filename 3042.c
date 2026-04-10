#include <stdio.h>
 
int main() {
    int n;     
    while(scanf("%d", &n), n){
        char pos = 'c'; 
        int t = 0; 
        for(int i = 0; i<n; i++){
            int l, c, r; 
            scanf("%d%d%d", &l, &c, &r);
            if(i){
                if(pos == 'c' && c){
                    if(!l){
                        pos = 'l';
                        t++;
                    }
                    else{
                        pos = 'r';
                        t++;
                    }
                }
                else if(pos == 'l' && l){
                    if(!c){
                        pos = 'c';
                        t++; 
                    }
                    else{
                        pos = 'r';
                        t+=2; 
                    }
                }
                else if(pos == 'r' && r){
                    if(!c){
                        pos = 'c';
                        t++;
                    }
                    else{
                        pos = 'l';
                        t+=2; 
                    }
            
                }
            }
        }   
        printf("%d\n", t);
    }
    
 
    return 0;
}