#include <bits/stdc++.h> 

using namespace std;

#define MAX 26

int main (){
    int n; 
    cin >> n; 
    cin.ignore(); 

    while(n--){
        string s; 
        getline(cin, s); 
        
        int v[MAX] = {}; //a = 0, b = 1, c = 2, ...

        // a = 122, b = 123, c = 124, ... 

        for(auto k: s){
            if(k >= 'a' && k <= 'z')
                v[k - 'a'] = 1; 
        }

        int c = 0; 
        for(int i = 0; i<MAX; i++)
            if(v[i]) c++; 

        if(c == 26) cout << "frase completa"; 
        else if(c > 12) cout << "frase quase completa"; 
        else cout << "frase mal elaborada"; 
        cout << endl; 
    }
}