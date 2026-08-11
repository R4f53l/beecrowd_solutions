#include <bits/stdc++.h> 

using namespace std; 
#define MAX 2
int main(){
    int n; cin >> n;
    vector<vector<int>> v(MAX); 
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;  
        v[b].push_back(a);
    }
    int l = 0, r = 0, t = 0, ans = -1; 
    for(int i = 0; i < n; i++){
        if(v[0][l] < v[0][r])
            ans = (v[0][l] + 10, ans); 
        else{
            t += 
        }
    }

}