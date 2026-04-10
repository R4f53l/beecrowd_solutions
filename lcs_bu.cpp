#include <bits/stdc++.h> 

using namespace std; 

int main (){
    string s, t; cin >> s >> t;
    vector<vector<int>> lcs_s(s.size()+1, vector<int>(t.size()+1)); 
    for(int i = s.size()-1; i>=0; i--){
        for(int j = t.size()-1; j>=0; j--){
            if(s[i] == t[j]) lcs_s[i][j] = 1 + lcs_s[i+1][j+1]; 
            else lcs_s[i][j] = max(lcs_s[i][j+1], lcs_s[i+1][j]);
        }
    }
    cout << lcs_s[0][0] << endl; 
}