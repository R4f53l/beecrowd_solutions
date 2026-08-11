#include <bits/stdc++.h> 

using namespace std; 

#define MAX 7

int main(){    
    int t; cin >> t; 
    while(t--){
        vector<bool> v(MAX, 0); 
        int n; cin >> n; 
        for(int i = 0; i < n; i++){
            int a; cin >> a; 
            v[a] = 1; 
        }
        int maior = -1, menor = 7; 
        for(int i = 1; i < MAX; i++){
            if(v[i]){
                menor = min(menor, i);
                maior = max(maior, i); 
            }
        }    
        cout << maior - menor + 1 << endl;     
    }
}