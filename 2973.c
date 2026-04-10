#include <stdio.h> 

int n, c, t;

long long eh_possivel (int *v, int m){
    long long cons = (long long) t*m;
    int comp = 1;      
    for(int i = 0; i<n; i++){
        if(cons >= v[i]) cons -= v[i];
        else {
            comp++; 
            cons = (long long) t * m; 
            i--; 
            if(comp > c) return 0;
        }
    }
    return 1; 
}



int main (){
    scanf("%d%d%d", &n, &c, &t);
    int v[n];
    for(int i = 0; i<n; i++)
        scanf("%d", &v[i]);   

    int i = 0, r = 1e9 + 1; 
    while(i < r){
        int m = (i+r)/2; 
        if(!eh_possivel(v, m)) i = m+1; 
        else r = m;
    }
    printf("%d\n", r);
}