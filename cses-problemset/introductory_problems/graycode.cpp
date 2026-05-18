#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
int n; 
vector <string> recursion(int i){
    if(i == 1)
        return {"0", "1"}; 
    vector<string> a = recursion(i - 1); 
    vector<string> b = a; 
    reverse(b.begin(), b.end()); 
    for(auto &s: a)
        s += '0';    //000 100 110 100  101 111 011 001     
    for(auto &s: b)
        s += '1';    
    
    a.insert(a.end(), b.begin(), b.end()); 
    return a; 
}

int main(){_
    cin >> n;
    vector<string> r = recursion(n); 
    for(auto k: r) cout << k << " "; 

} 