#include <bits/stdc++.h>
#define max 4

using namespace std; 

int main () {
    int i, a; 
    vector<int> v; 
    for(i=0; i<max; i++){
        cin >> a; 
        v.push_back (a);
    }
    sort (v.begin(), v.end());
    
    if(v[0] + v[1] > v[2])
        printf("S\n");
    else if(v[1] + v[2] > v[3])
        printf("S\n");
    else 
        printf("N\n");
        
    return 0;
}
