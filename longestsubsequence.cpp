#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define MAX 5400
vector<int> v = {6, 2, 5, 1, 7, 4, 8, 3};
vector<int> tamanho (MAX, 1); 

int main (){
    for(int i = v.size() - 1; i >= 0; i--){        
        for(int j = i + 1; j < v.size(); j++){
            if(v[i] < v[j])
                tamanho[i] = max(tamanho[i], tamanho[j] + 1); 
        }
    }
    for(int i = 0; i < v.size(); i++)
        cout << tamanho[i] << " "; 
}