#include <bits/stdc++.h> 

using namespace std; 

int main (){
    vector<int> v = {0, 0, 0}; 
    sort(v.begin(), v.end()); //two pointers exige array ordenado
    int target = 1, menor = 0x3f3f3f3f, soma; 
    for(int i = 0; i < v.size(); i++){
        if(i && v[i] == v[i - 1]) continue; 
        int need = target - v[i]; 
        int l = i + 1, r = v.size() - 1; 
        while(l < r){
            if(menor > abs(target - (v[i] + v[l] + v[r]))){
                menor = abs(target - (v[i] + v[l] + v[r]));
                soma = v[i] + v[l] + v[r];  
            }
            if(v[l] + v[r] > need) r--; 
            else if(v[l] + v[r] < need) l++;             
        }
    }
    cout << soma << endl; 
}