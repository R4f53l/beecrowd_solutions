#include <bits/stdc++.h> 

using namespace std; 
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 41

vector<int> fibo(MAX); 

int main(){_    
    fibo[0] = 1, fibo[1] = 2; 
    for(int i = 2; i <= MAX - 1; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2]; 
    int n; cin >> n; 
    cout << fibo[n - 1] << endl; 
}