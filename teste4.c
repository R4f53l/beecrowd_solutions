#include <stdio.h> 
#include <stdlib.h> 

int main () {
    int n, i, *v, m = 1; 
    scanf("%d", &n);
    v = (int*) malloc (sizeof(int)*n);
    for(i=0; i<n; i++)
        scanf("%d", v+i);
    if(n == 1) printf("1\n");
    else if (n == 2){
        if(v[0] == v[1]){
            printf("0\n");
            exit(1);
        }
    }
    else{
        if(v[0] > v[1]){
            for(i=2; i<n-1; i++){
                if(!(i%2)){
                    if(v[i] <= v[i+1]){
                        m = 0;        
                        break;
                    }         
                }
                else {
                    if(v[i] >= v[i+1]){
                        m = 0; 
                        break;
                    }   
                }
            }
        }
        else if(v[0] < v[1]){
            for(i=2; i<n-1; i++){
                    if(!(i%2)){
                        if(v[i] >= v[i+1]){
                            m = 0; 
                            break;
                        }
                    }
                    else {
                        if(v[i] <= v[i+1]){
                            m = 0; 
                            break;
                        }
                    }
                }
            }                 
            printf("%d\n", m);
        }
            
    }   

