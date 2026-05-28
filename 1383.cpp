#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 10

int main(){_
    int n, cont = 1; ; cin >> n; 
    while(n--){
        bitset<MAX> b[MAX], l[MAX], c[MAX];
        int possible = 1; 
        for(int i = 0; i < MAX - 1; i++){
            for(int j = 0; j < MAX - 1; j++){
                int a; cin >> a; 
                if(l[i][a] || c[j][a] || b[(i/3) * 3 + (j / 3)][a]) possible = 0;
                l[i][a] = 1; 
                c[j][a] = 1;  
                b[(i/3) * 3 + (j / 3)][a] = 1; 
            }
        }
        cout << "Instancia " << cont++ << endl;
        cout << (possible ? "SIM" : "NAO") << endl;
        cout << endl;

    }
}