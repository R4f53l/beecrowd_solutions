#include <stdio.h>
#include <ctype.h> 
#include <string.h> 
 
int main() {
    int n, t, i, j; 
    char m [101][500], nf [101][500], s[101], inv [101], nfi[101][500];
    
    scanf("%d%d", &n, &t);
    
    for(i = 0; i<n; i++){
        scanf("%s", s);
        for(j = 0; s[j]; j++)
            s[j] = tolower(s[j]);
        strcpy(nf[i], s);
        for(j = 0; s[j]; j++)
            inv[j] = s[strlen(s)-j-1];
        inv[j] = 0;
        strcpy(nfi[i], inv);
    }  
    
    for(i = 0; i<t; i++){
        scanf("%s", s);
        for(int j = 0; s[j]; j++)
            s[j] = tolower(s[j]);
        strcpy(m[i], s);
    }
    
    for(i = 0; i<n; i++){
        int p = 0;
        for(int j = 0; j<t; j++){
            if(strstr(m[j], nf[i]))
                p = 1; 
            if(strstr(m[j], nfi[i]))
                p = 1; 
        }        
        if(p) printf("Sheldon come a fruta %s\n", nf[i]);
        else printf("Sheldon detesta a fruta %s\n", nf[i]);
    }
        
    return 0;
}