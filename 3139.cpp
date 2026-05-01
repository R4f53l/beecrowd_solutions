#include <bits/stdc++.h>

using namespace std; 

#define MAX 30
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n, s, cont = 0, m; cin >> s >> n; 
    deque<int> v(MAX); 
    for(int i = 0; i < MAX; i++)
        cin >> v[i];  
    
    while(1){
        cont++;        
        int sum = 0;        
        for(int i = 0; i < MAX; i++)
            sum += v[i];
        m = ceil((double) sum / MAX); 
        s += m;
        if(s >= n) break;
        v.pop_front(); v.push_back(m);        
        cout << endl;
        int p = 0;
        for(int i = 0; i < MAX - 1; i++){
            if(v[i] != v[i + 1]) p = 1;            
        }        
        if(!p) break; 
    }

    //105 -> 126 - 105 = ceil(21 / 5) = 5 + 1 = 6
    if(s >= n) cout << cont << endl;
    else cout << (int) ceil((double)(n - s)/ m) + cont << endl;
}