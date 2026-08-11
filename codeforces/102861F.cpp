#include <bits/stdc++.h> 

using namespace std; 

int main (){
    bool saque = 0; //0 left 1 right
    vector<int> p(2, 0), g(2, 0); 
    string s; cin >> s; 
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'S') p[saque]++; 
        else if (s[i] == 'R') {
            saque ^= 1; 
            p[saque]++; 
        }
        else{
            if(g[0] < 2 && g[1] < 2) printf("%d (%d%s - %d (%d%s\n", g[0], p[0], saque ? ")" : "*)", g[1], p[1], saque ? "*)": ")"); 
            else {
                if(g[0] == 2) printf("%d (winner) - %d\n", g[0], g[1]); 
                else printf("%d - %d (winner)", g[0], g[1]); 
            }
        }
        if(p[0] >= 10 || p[0] >= 5 && p[0] - p[1] >= 2){
            g[0]++, p[0] = 0, p[1] = 0; 
        }        
        else if(p[1] >= 10 || p[1] >= 5 && p[1] - p[0] >= 2){
            g[1]++, p[1] = 0, p[0] = 0; 
        } 
        
    }
}