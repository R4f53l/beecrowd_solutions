#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){
    int n; cin >> n;
    stack<pair<int, int>> s; 

    for(int i = 0; i < n; i++){
        int a; cin >> a; 

        while(!s.empty() && s.top().first >= a)
            s.pop(); 
        
        if(s.empty())
            cout << "0 ";        
        
        else cout << s.top().second << " ";    

        s.push({a, i + 1});
    }

}