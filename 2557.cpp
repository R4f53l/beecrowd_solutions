#include <bits/stdc++.h> 

using namespace std; 

int main () {
    string s;     
    while(cin >> s){ 
        string o = "", o1 = "";
        int i = 0, p = 0; 
        while(s[i]){
            while(!isdigit(s[i]) && s[i]) i++; 
            while(isdigit(s[i]) && !p && s[i]){
                o += s[i];
                i++; 
            }            
            while(isdigit(s[i]) && p && s[i]){
                o1 += s[i];
                i++; 
            }          
            p = 1; 
        }
        int a = stoi(o), b = stoi(o1);
        int pos = s.find('='); 
        printf("%d\n", isdigit(s[pos+1])? b-a: a+b);
    }
}