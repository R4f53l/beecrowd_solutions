#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main (){
    long long n; cin >> n; 
    while(true){
        cout << n << " "; 
        if(n == 1) break;
        n = (n % 2) ? n * 3 + 1 : n / 2; 
    }
}