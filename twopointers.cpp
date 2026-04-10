#include <bits/stdc++.h> 

using namespace std; 
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
int main (){_
    vector<int> v = {1, 3, 2, 5, 1, 1, 2, 3};
    int target = 8; 

    int i, l = 0, soma = 0; 

    for(i = 0; i < v.size(); i++){
        if(soma == target) break;
        soma += v[i]; 
        if(soma > target && l <= i){
            soma -= v[l]; l++;
        }
    }

    cout << i-1 << " " << l << endl; 

    
        

}