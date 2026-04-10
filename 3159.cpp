#include <bits/stdc++.h> 

using namespace std; 

int main (){
    int n; cin >> n;
    cin.ignore();
    vector<string> v = {"","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    while(n--){
        string s; getline(cin, s);  
        int ant = -1; 
        for(int i = 0; s[i]; i++){
            int f = 0; 
            if(s[i]>= 'A' && s[i] <= 'Z') {cout << "#"; f = 1;}
            if(s[i] == ' '){
                 cout << "0"; ant = 0; 
            }
            s[i] = tolower(s[i]);
            for(int j = 0; j<v.size(); j++){
                int a = v[j].find(s[i]); 
                if(a != string::npos){
                    if(j == ant && !f) cout << "*"; 
                    for(int z = 0; z<=a; z++)
                        cout << j+1; 
                    ant = j; 
                }
            }
        }cout << endl; 
    }
}