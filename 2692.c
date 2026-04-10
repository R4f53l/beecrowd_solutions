#include <stdio.h>

typedef struct {
    char first; 
    char second; 
}pair; 

int main() {
    int n, m, i = 0; 
    scanf("%d%d", &n, &m);
    pair v[n];
    while(n--){
        char a, b; 
        scanf(" %c %c", &a, &b);
        v[i].first = a; 
        v[i].second = b; 
        i++; 
    }
    while(m--){
        char s[100];
        scanf(" %[^\n]", s);
        for(int z = 0; s[z]; z++){
            for(int j = 0; j<i; j++){
                if(v[j].second == s[z]){
                    s[z] = v[j].first;
                    continue;
                }
                if(v[j].first == s[z]){
                    s[z] = v[j].second;
                    continue; 
                }
            }
        }
        printf("%s\n", s);
    }
    
 
    return 0;
}