#include <bits/stdc++.h>

using namespace std; 

int main (){
    int n, c = 1; 
    cin >> n; 
    cin.ignore();
    while(n--){
        string o, s1, s2;  
        
        getline(cin, o); getline(cin, s1); getline(cin, s2);
        
        int cont1 = 0, cont2 = 0, e1 = -1, e2 = -1;        
        for(int i = 0; o[i]; i++){
            if(o[i] == s1[i]) cont1++; 
            else{
                if(o[i] == s2[i] && e1 == -1)
                    e1 = i;
            }
            if(o[i] == s2[i]) cont2++; 
            else {
                if(o[i] == s1[i] && e2 == -1)
                    e2 = i; 
            }
        }
            
          
        cout << "Instancia " << c++ << endl; 
        
        if(cont1 > cont2) cout << "time 1" << endl; 
        else if(cont1 < cont2) cout << "time 2" << endl; 
        else {
            if(e1 == e2) cout << "empate" << endl; 
            else if(e1 < e2) cout << "time 2" << endl; 
            else cout << "time 1" << endl; 
        }

        cout << endl; 
    }
}