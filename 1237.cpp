#include <bits/stdc++.h> 

using namespace std; 

void solve (string a, string b){
    int maior = 0; 
    for(int i = 0; a[i]; i++){ //abcdef
        for(int j = 0; b[j]; j++){ //cdofhij 
            int c = 0; 
            if(a[i] == b[j]) {                     
                for(int k = 0; k+i < a.length()|| k+j < b.length(); k++){
                    if(a[k+i] != b[k+j])
                        break; 
                    c++; 
                }
            }
            maior = c > maior ? c : maior; 
        }
    }
    printf("%d\n", maior);
}

int main () {
    string s, s1; 
    while(getline(cin, s) && getline(cin, s1)){
        solve(s, s1);
    }
}