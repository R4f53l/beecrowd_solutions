#include <bits/stdc++.h> 

using namespace std; 

int main (){
    int n, r = 0; 
    string s = "FACE"; 
    cin >> n; 
    cin.ignore();
    for(int i = 0; i<n; i++){
        int cont = 0, t = 0; 
        string o; 
        for(int i = 0; i<4; i++){
            char c; cin >> c;
            o += c;
        }         
        
        for(int j = 0; j<s.size(); j++){
            if(j+3 >= s.size()-1){
                if(s[j] == o[o.size()-t-1]) cont++; 
                t++; 
            }
        }
        if(cont < 4) s += o; 
        else {
            r++; 
            for(int i = 0; i<4; i++)
                s.pop_back(); 
            if(s.size() == 0) s = "FACE"; 
            
        }
        
    }
    cout << r << endl; 
}