#include <bits/stdc++.h>

using namespace std; 

vector <int> v = {10, 20, 30, 40, 50, 60, 70, 80}; 

int ternary_search (int target){
    int i = 0, f = v.size() - 1; 
    while(i <= f){  
        int m1 = i + (f - i)/3, m2 = f + (f - i)/3; 

        if(v[m1] > target && v[m2] > target) 
            i = m1 + 1, f = m2 - 1; 
        else if(v[m1] > target)
            f = m1 - 1; 
        else if(v[m2] < target)
            i = m2 + 1; 

    }    

    return i; 
}

int main (){

}