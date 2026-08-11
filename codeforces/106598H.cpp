#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int n, sum = 0; cin >> n;     
    for(int i = 0; i < n; i++){
        int a; cin >> a; 
        sum += a; 
        if(sum > 120 && sum <= 300) sum += 180; 
        if(sum > 720 && sum <= 900) sum += 180; 
    }
    cout << sum << endl; 
}