#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 



int main(){_ 
    int n, x, y; 
    cin >> n >> x >> y; 
    int target = 1 << (n - 1), cont = 0;     
    while(x != target || y != target){        
        int i = (x > target ? 1 << n : 0); 
        int j = (y > target ? 1 << n : 0);
        x = 2 * x - i; 
        y = 2 * y - j;        
        cont++; 
    }
    cout << cont << endl; 

}