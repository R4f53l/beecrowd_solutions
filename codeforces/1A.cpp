#include <bits/stdc++.h> 

using namespace std;

int main(){
    int n, m, a; cin >> n >> m >> a; 
    long long x = ceil((double)n / a);
    long long y = ceil((double)m / a);
    cout << x * y << endl; 
}