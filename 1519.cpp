#include <bits/stdc++.h> 

using namespace std; 

int main (){
    string s; 
    vector<string> v = {"", "ABCabc", "DEFdef", "GHIghi", "JKLjkl", "MNOmno", "PQRSpqrs", "TUVtuv", "WXYZwxyz"}; 
    while(getline(cin, s)){

        for(int i = 0; s[i]; i++){
            for(int j = 0; j<v.size(); j++){
                if(v[j].find(s[i]) != string::npos) s[i] = (char) j + 49;  
            }
        }
        
        for(char k: s){
            if(isdigit(k) || k == '*' || k == '#') cout << k; 
        }cout << endl;    

            
    }
}