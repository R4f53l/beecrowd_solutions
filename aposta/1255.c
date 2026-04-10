#include <stdio.h>
#include <ctype.h> 
 
int main() {
    int n, maior; 
    scanf("%d%*c", &n);
    while(n--){
        int v[128] = {0};
        char s[201];

        scanf("%[^\n]%*c", s);

        for(int i = 0; s[i]; i++){
            char o = tolower(s[i]);
            if(isalpha(o)) v[(int)o]++;
        }

        for(int i = 0; i<128; i++){
            if(!i) maior = v[i];
            else {
                if(maior < v[i]) maior = v[i];
            }
        }
        
        for(int i = 97; i<128; i++){
            if(v[i] == maior && i!=32) printf("%c", i);
        }
        
        printf("\n");
        
    }
 
    return 0;
}