#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n, x; cin >> n >> x; 
    vector<int> v(n); 

    for(auto &i: v) cin >> i; 

    int sum = 0, l = 0, cont = 0;

    for(int i = 0; i < n; i++){           
        sum += v[i];     //2 + 4 + 1 = 7 + 2 -> 7 + 7 = 14 

        while(sum > x && l < i){
            sum -= v[l];            
            l++; 
        }             
            
            
        if(sum == x) cont++;
    }
    //2 + 4 + 1 = 7; 7 + 2 = 9;
    cout << cont << endl;

}