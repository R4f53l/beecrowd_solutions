#include <bits/stdc++.h> 

using namespace std; 

int sum_of_digits(int n){
    int sum = 0; 
    while(n){
        sum += n % 10; 
        n /= 10; 
    }
    return sum; 
}

int main (){
    map<int, int> m; 
    int n, k; cin >> n >> k; 
    for(int i = 0; i < n; i++){
        int a; cin >> a; 
        m[a]++; 
    }
    
    for(auto [a, f]: m)
        m[a - sum_of_digits(a)] = f; 
    
}