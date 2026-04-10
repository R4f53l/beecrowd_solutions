#include <bits/stdc++.h> 

using namespace std; 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
const int MAX = 1e5 + 10;

int n, c, t; 
int v[MAX];

int eh_possivel (long long p){
    long long chute = p * t; 
    int comp = 1; 
    for(int i = 0; i<n; i++){        
        if(chute >= v[i]) chute -= v[i];
        else {
            comp++; 
            chute = p*t; 
            i--;             
        }
        if(comp > c) return 0;
    }
    return 1; 
}

int main () {_
    
    cin >> n >> c >> t; 
    
    
    for(int i = 0; i<n; i++)
        cin >> v[i];

    int l = 0, r = 1e9 + 1; 

    while(l < r){
        int m = (r+l)/2;
        if(!eh_possivel(m)) l = m+1; 
        else r = m; 
    }

    cout << l << endl;


}