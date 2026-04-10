#include <bits/stdc++.h> 


void solve (string a, string b){
    int maior = 0; 
    for(int i = 0; a[i]; i++){
        for(int j = 0; b[j]; j++){
            if(a[i] == b[j])
                c++; 
            else{
                maior = maior < c? c : maior; 
                c = 0; 
            } 
        }
    }
    printf("%d\n", maior);
}

int main () {
    string s, s1; 
    while(getline(cin, s) && getline(cin, s2)){
        solve(s, s1);
    }
}