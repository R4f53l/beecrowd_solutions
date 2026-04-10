#include <stdio.h>
#include <math.h>
 
int main() {
 int Q, L, R, acm=0, i;
 float raiz;
 scanf("%d", &Q);
 
  for(i=0; i<Q; i++){
     scanf("%d %d", &L, &R);
     raiz=ceil(sqrt(L));
     for(;raiz*raiz<=R;raiz++){ 
       acm++;
    
     }
     printf("%d\n", acm);
     acm=0;
 }
   
 
    return 0;
}