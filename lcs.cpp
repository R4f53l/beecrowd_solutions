#include <bits/stdc++.h> 

using namespace std; 

const int MAX = 3010; 
string s, t; 
int memo[MAX][MAX];

int lcs_size (int i, int j){
    if(i >= s.size() || j >= t.size()) return 0; 
    int &p = memo[i][j];
    if(s[i] == t[j]) return p = 1 + lcs_size(i+1, j+1);
    else return p = max(lcs_size(i+1, j), lcs_size(i, j+1));
}

int main (){
    cin >> s >> t; 
    memset(memo, -1, sizeof(memo));
    cout << lcs_size(0, 0) << endl; 

}