#include <stdio.h>
#include <ctype.h> 
#define max 1001
int main() {
    int c, n, first = 1; 
    while(~scanf("%d%d", &c, &n)){
        char s[c], aux[c], o[max];
        scanf(" %[^\n] %[^\n]", s, aux);
        for(int i = 0; i<n; i++){
            scanf(" %[^\n]", o);
            for(int j = 0; o[j]; j++){
                char t = o[j];
                for(int z = 0; s[z]; z++){
                    if(tolower(s[z]) == tolower(o[j])){
                        if(isupper(t))
                            o[j] = toupper(aux[z]);
                        else o[j] = tolower(aux[z]);
                        break;
                    }
                    else if(tolower(aux[z]) == tolower(o[j])){
                        if(isupper(t))
                            o[j] = toupper(s[z]);
                        else o[j] = tolower(s[z]);
                        break;
                    }
                }
            }
            
            printf("%s\n\n", o);
        }
        
    }
    
 
 
    return 0;
}