#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main (){
    vector<int> v = {1, 4, 5, 6, 7, 9, 9, 10}; 
    int target = 12; 

    //como o vetor ja esta ordenado...
    int i = 0, f = v.size() - 1; 

    while(i < f){ //precisam ser dois indices distintos do vetor 
        if(v[i] + v[f] > target) f--; 
        else if(v[i] + v[f] < target) i++;
        else break;
    }
    cout << i << " " << f << endl; 
}