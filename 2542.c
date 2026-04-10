#include <stdio.h>
 
int main() {
    int n; 

    while(~scanf("%d", &n)){
        int cm, cl, a;
         
        int m, l; 
        scanf("%d%d", &m, &l);
        int mm[m][n], ml[l][n];

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++)
                scanf("%d", &mm[i][j]);
        }

        for(int i = 0; i<l; i++){
            for(int j = 0; j<n; j++)
                scanf("%d", &ml[i][j]);
        }

        scanf("%d%d%d", &cm, &cl, &a);
        
        if(mm[cm-1][a-1] > ml[cl-1][a-1]) printf("Marcos\n");
        else if(mm[cm-1][a-1] < ml[cl-1][a-1]) printf("Leonardo\n");
        else printf("Empate\n");            
        
    }
 
    return 0;
}