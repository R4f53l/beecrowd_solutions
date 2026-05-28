#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int get_max(int n){
    int ans = -1; 
    while(n){        
        ans = max(n % 10, ans); 
        n /= 10; 
    }
    return ans; 
}

int main(){_
    int n, cont = 0; cin >> n; 
    while(n){
        int value = get_max(n); 
        cout << endl;
        n -= value; 
        cont++;
    }
    cout << cont << endl; 
}