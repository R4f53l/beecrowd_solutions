#include <stdio.h> 
#include <math.h> 

#define MAX 100101
int n, a; 
int v[MAX]; 

double sum (double mid){
    double soma = 0; 
    for(int i = 0; i < n; i++){
        if((double)v[i] > mid) soma +=  ((double) v[i] - mid); 
    }
    return soma; 
}

double binary_search (int maior){
    double l = 0, r = maior; //maior valor possivel de altura
    for(int i = 0; i < 100; i++){ //while((r - l) < 1e-3)
        double m = (l + r)/2.0, value = sum(m);
        if(value > (double) a) l = m; 
        else r = m; 
    }
    if(fabs(sum(l) - a) <= 1e-3) return l;
    return -1; 

}

int main (){    
    while(scanf("%d %d", &n, &a), n){    
        int maior = -1; 
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]); 
            maior = v[i] > maior ? v[i] : maior;
        }
        
        double ans = binary_search(maior); 
        if(fabs(ans - 0) <= 1e-3) printf(":D\n"); 
        else if(fabs(ans + 1) <= 1e-3) printf("-.-\n"); 
        else printf("%.4lf\n", ans); 
    }
}