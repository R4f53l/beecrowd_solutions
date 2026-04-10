#include <bits/stdc++.h>

using namespace std; 

double fa(double x){
    return -(x * x) + 2 * x + 1;
}

double ternary_search (){
    double i = 0.0, f = 50.0;

    while(abs(i - f) > 1e-9){
        double m1 = i + (f - i) / 3; double m2 = f - (f - i)/3;
        
        if(fa(m1) < fa(m2))
            i = m1; 
        else f = m2; 

    }
    return (i + f)/2;
}

int main (){
    cout << ternary_search(); 
}