#include <bits/stdc++.h>
using namespace std; 
int main () {
    string s;
    bool m;
    scanf("%s"); 
    
    for(int i=0; s[i]; i++){
        if(s[i]=='1' && s[i+1]=='3')
            m = true;             
    }
    if(m)
        printf("%s es de Mala Suerte", s);
    else 
        printf("%s NO es de Mala Suerte", s);








    return 0; 
}