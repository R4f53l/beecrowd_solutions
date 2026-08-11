#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int n; cin >> n; 

    
    //desenha lateral
    
    for(int i = 0; i < 2 * n + 1; i++){   
        if(i < n) cout << ' ';     
        else cout << '_'; 
    }
    cout << endl;   

    for(int i = 0; i < n; i++){
        for(int z = n - 1 - i; z > 0; z--) cout << ' '; 
        cout << '/';         
        for(int z = 0; z < n + 1 + 2*i; z++){
            if(i == n - 1){
                if(z < n) cout << '_';
                else cout << ' '; 
            }
            else cout << ' '; 
            
        }
        
        cout << '\\'; 
        if(i < n - 1) cout << endl;
    }    
    for(int i = 0; i < n + 1; i++)
        cout << '_'; 
    cout << endl; 
         
    for(int i = 0; i < n; i++){        
        for(int z = 0; z < n + i + 1; z++) cout << ' '; 
        cout << '\\';
        //5 * n  - (n + i ) = 5 * n - n - i
        for(int z = 0; z < 2 * n - 2 * i + n - 1; z++){
            if(i == n - 1){
                if(z < n + 1) cout << '_';
                else cout << ' '; 
            }
            else cout << ' ';          
        }
        cout << '/';
        if(i < n - 1) cout << endl; 
    }   
    
}