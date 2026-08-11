#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define MAX 26

int main (){_ 
    map<string, int> m; 
    int n, c; cin >> n >> c; 
    
    for(int i = 0; i < n; i++){
        string s; cin >> s; 
        auto it = s.find('*'); 
        for(int j = 0; j < MAX; j++){
            s[it] = j + 'a'; 
            m[s]++; 
        }
    }
    int best = -1; 
    string ans; 
    for(auto [c, v]: m){
        if(v > best){
            ans = c;
            best = v; 
        }
        if(v == best && c < ans) ans = c; 
    }

    cout << ans  << " " << best << endl; 

    
    
}