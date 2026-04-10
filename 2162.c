#include <stdio.h>
#include <stdbool.h>
 
int main() {
    int n, v[101], i = 0, aux;
    bool m, b = true;
    scanf("%d", &n);
    while(n--){
        int a; 
        scanf("%d", &a);
        v[i] = a; 
        i++;
    }
    aux = i;
    for(i=0; i<aux; i++){
        if(!i)
            m = v[i] > v[i+1] ? true: false; 
        if(m){           
            if(v[i]%2) 
            b =  v[i] < v[i+1];
            else 
            b =  v[i] > v[i+1];
        }
        else{
            if(v[i]%2==0)
            b =  v[i] > v[i+1];
            else 
            b =  v[i] > v[i+1];
        } 
        if(!b) break;           
    }
    if(b)
        printf("1\n");
    else 
        printf("0\n");
 
    return 0;
}