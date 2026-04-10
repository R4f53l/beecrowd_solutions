#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int i;
    
    string s; 
    while(getline(cin, s)){
        bool masc = false, min = false, dig = false, si = false;
        int size = s.size();
        for(i=0; s[i]; i++){
            if(s[i]>='A' && s[i]<='Z')
                masc = true;
            if(s[i]>='a' && s[i] <='z')
                min = true; 
            if(isdigit(s[i]))
                dig = true; 
            if(s[i]>=32 && s[i]<=47 || s[i] >=58 && s[i]<=64 || s[i]>=91  && s[i]<=96 || s[i]>=123 && s[i]<=126)
                si = true; 
            
        }
        if(!masc || !min || !dig || s.size()<6 || s.size()>32)
            si = true;
        if(masc){
            if(min){
                if(dig){
                    if(!si){
                            printf("Senha valida.\n");
                    }
                        
                }
            }
        }
        
        if(si)
            printf("Senha invalida.\n");
       
    }
    
 
    return 0;
}