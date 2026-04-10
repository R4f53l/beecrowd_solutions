#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, v[2000] = {0}, maior=0;
    cin >> n; 
    while(n--){
        int x, i;
        cin >> x; 
        v[x]++;
        maior = maior<x?x:maior;
        }
    for(int i=1; i<=maior; i++){
        if(v[i])
        cout << i << " aparece " << v[i] << " vez(es)" << endl;
    }
   
    
    return 0;
}