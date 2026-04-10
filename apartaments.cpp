#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main (){
    int n, m, k; 
    cin >> n >> m >> k; 
    vector<int> pref(n), apdimensions(m); 

    for(auto &x: pref) cin >> x; 
    for(auto &x: apdimensions) cin >> x; 

    sort(pref.begin(), pref.end()); 
    sort(apdimensions.begin(), apdimensions.end()); 

    int alocations = 0; 
    int i = 0, j = 0; 
    while(i < pref.size() && j < apdimensions.size()){    
        if(apdimensions[j] < pref[i] - k) j++; 
        else if(apdimensions[j] > pref[i] + k) i++; 
        else {
            alocations++; i++; j++; 
        }
        
    }

    cout << alocations << endl; 


}