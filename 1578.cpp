#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n, cont = 4; cin >> n; 
    while(n--){
        int tam; cin >> tam; 
        vector<vector<unsigned long long>> m (tam, vector<unsigned long long> (tam)); 
        vector<int> largura(tam, 0);   
        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                unsigned int a; cin >> a; 
                m[i][j] = (unsigned long long) a * a; 
                largura[j] = max(largura[j], (int) to_string(m[i][j]).size()); 
            }
        }
        cout << "Quadrado da matriz #" << cont++ << ":" << endl; 
        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                cout << setw(largura[j]) << m[i][j];
                if(j < tam - 1) cout << " ";  
            }
            cout << endl; 
        }
        if(n) cout << endl;
    }
}