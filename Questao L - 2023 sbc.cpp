#include <bits/stdc++.h> 

using namespace std;

int main () {
    int k, start = 0; 
    string s;
    cin >> s >> k; 
    
    for(int z = 0; z<k; z++){
        string p; 
        
        for(int i = z; i < s.size() ; i+=k)
            p += s[i]; 
        
        sort(p.begin(), p.end()); 
    
        int idx = 0; 
    
        for(int i = z; i<s.size(); i+=k)
            s[i] = p[idx++];
    
        
    }
    
    cout << s << endl; 
    
}