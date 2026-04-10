#include <stdio.h> 

int main () {
    int t; 
    scanf("%d", &t);
    while(t--){
        float r, g, b, min, max, mean, eye; 
        char s[5];
        scanf("%s", s);
        scanf("%f%f%f", &r, &g, &b);
        if(!strcmp(s, "min")){
            if(r <= g && r <= b)
                min = r; 
            else if(g <= r && g <= b)
                min = g; 
            else 
                min = b;             
            printf("%0.f\n", min);    
        }
        else if(strcmp(s, "max")){
            if(r>=g && r>= b)
                max = r; 
            else if(g >= r && g >= b)
                max = g; 
            else 
                max = b; 
            printf("%0.f\n", max);     
        }
        else if(strcmp(s, "mean")){ 
            mean = (r + g + b)/3; 
            printf("%0.f\n", mean);
        }
        else {
            eye = 0.3*r + 0.59*g + 0.11*b; 
            printf("%0.f\n", eye);
        }

        

    }
}