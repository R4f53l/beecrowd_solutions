#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 20

int main(){
    vector<int> fibo(MAX); 
    fibo[0] = 1, fibo[1] = 2; 
    for(int i = 2; i < MAX; i++)
        fibo[i] = fibo[i - 2] + fibo[i - 1]; 

    int cases; cin >> cases; 
    while(cases--){
        int x; cin >> x; 
        string s; 
        //4 % 2 = 0, 2 % 2 = 0, 1 
        
        bool t = 0; 
        for(int i = MAX - 1; i >= 0; i--){
            if(x >= fibo[i]){
                s += '1'; 
                x -= fibo[i]; 
                t = 1;
            }
            else if(t && x < fibo[i]) s += '0'; 
        }    
        
        s.pop_back(); 
        
        int ans = 0; 
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '0') ans += fibo[s.size() - i - 1]; 
            
        }
        cout << ans << endl; 
    }

}