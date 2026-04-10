#include <stdio.h>
 
int main() {
    int hi, mini, hf, minf; 
    while(scanf("%d %d %d %d", &hi, &mini, &hf, &minf)){
        if(!hi && !mini && !hf && !minf) break;
        int min, h;

        if(hf-hi<=0){
            h = hf - hi; 
            min = minf - mini;
            
            if(hf-hi==0){
                if(minf-mini<0){
                    h+=23;                                                        
                    min+=60;  
                }
                else if(minf-mini>0)                    
                    min=minf-mini;
                else{ 
                    h+=23; 
                    min+=60;
                }                                 
            }

            else
                h+=24;                             
        }
        else {
            h = hf-hi; 
            min = minf - mini; 
        }
        
        printf("%d\n", h*60+min);
    }
 
    return 0;
}