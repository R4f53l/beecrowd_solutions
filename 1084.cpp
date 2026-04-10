#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 


int main (){_
    int n, d; 
    while(cin >> n >> d, n){
        string s; cin >> n; 
        
        deque<char> p; p.push_back(s[0]); 
        
        for(int i = 1; i<s.size(); i++){
            while(p.size() && s[i] > p.back() && d){
                p.pop_back(); 
                d--; 
            }   
            p.push_back(s[i]); 
        }
        
        while(d){
            p.pop_back(); d--;
        }
        
        for(int i = 0; i<p.size(); i++)
            printf("%c", p[i]); 
        printf("\n"); 
        
    }
    
    return 0;
}