#include <stdio.h> 
#include <string.h> 

int main (){
    int v, m; scanf("%d%d", &v, &m); 
    int c[m], dp[v+1]; 
    memset(dp, 0, sizeof dp); 
    for(int i = 0; i<m; i++)
        scanf("%d", &c[i]); 
    dp[0] = 1; 
    for(int i = 0; i<m; i++){
        for(int j = v; j>=c[i]; j--){
            if(dp[j - c[i]])
                dp[j] = 1; 
        }
    }
    printf("%s\n", dp[v] ? "S" : "N"); 
}