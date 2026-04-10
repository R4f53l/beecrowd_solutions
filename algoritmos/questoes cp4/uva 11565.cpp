#include <bits/stdc++.h> 

using namespace std; 

int main (){
    /* questao: encontrar x, y, z, tal que x != y != z e
        onde x + y + z == A, xyz = B e x^2 + y^2 + z^2 = C

        onde A, B, C <= 10000
    */
    
    int x, y, z, sol = 0; 

    //x + y + z = A -> z = A - x - y; 

    for(x = -22; x <= 22 && !sol; x++){
        if(x <= A && (x * x) <= C)
        for(y = -100; y <= 100; y++){
            if((x + y) <= A && (x * x) + (y * y) <= C)
            for(z = -100; z <= 100; z++){
                if(x != y && y != z){
                    if(x + y + z == A && x * y * z == B 
                        && x * x + y * y + z * z == C){
                        printf("%d, %d, %d\n", x, y, z); 
                        sol = 1; 
                    }
                }
            }            
        }
    }


}