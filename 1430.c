#include <stdio.h> 
#include <string.h> 
int main () {
    char s[21];
    while(scanf("%s", s)){
        int i, c = 0, j; 
        float v[21] = {0}; 
        for(i=0; s[i]; i++){
            if(s[i] == '/'){
                i++; 
                while(s[i++] != '/'){
                    printf("oi\n");
                    if(s[i] == 'W') v[c]+=1; 
                    else if(s[i] == 'H') v[c]+=0.5;
                    else if(s[i] == 'Q') v[c]+=0.25;
                    else if(s[i] == 'E') v[c]+=0.125;
                    else if(s[i] == 'S') v[c]+=0.0625;
                    else if(s[i] == 'T') v[c]+=0.03125;
                    else v[c]+=0.015625;
                }
                c++;
            }
        }
        for(j=0; j<21; j++)
            printf("%.1f ", v[j]);
    }
        
       
    

}