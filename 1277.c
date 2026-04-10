#include <stdio.h> 
#include <string.h> 

struct aluno {
    char s[51]; 
    int pf; 
}; 

int main () {
    int t; 
    scanf("%d", &t);
    while(t--){
        int n, c = 0, qf = -1;
        struct aluno v[101];
        char o, f[51];
        scanf("%d", &n);
        do {
            scanf("%s", v[c++].s);
            o = getchar(); 
        }while(o!='\n');
        o = 'a';
        c = 0; 
        do {
            int a = 0, p = 0;
            scanf("%s", f);
            o = getchar ();
            for(int i = 0; f[i]; i++){
                if(f[i] == 'A') a++; 
                if(f[i] == 'P') p++;
            }
            float tf = (float) a/(p+a);
            if(tf>0.25) qf++;
            v[c++].pf = tf>0.25? 1: 0; 
        }while(o!='\n');
        int u = 0;
        for(int i = 0; i<c; i++){            
            if(v[i].pf){                
                if(u<qf) printf("%s ", v[i].s);
                else printf("%s\n", v[i].s);
                u++;
            }
            if(qf == -1) printf("\n");
            
        }
    }
}