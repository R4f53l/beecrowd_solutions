#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main (){_
    int n; cin >> n; 

    long long r = (long long) n * (n + 1)/2, soma1 = 0;

    vector<int> ans1, ans2; 

    if(r % 2) cout << "NO" << endl; 
    else{
        for(int i = n; i >= 1; i--){
            if(soma1 + i <= r/2){
                ans1.push_back(i); soma1 += i;
            }
            else ans2.push_back(i);
        }
        cout << "YES" << endl; 
        cout << ans1.size() << endl;
        for(auto i: ans1) cout << i << " "; 
        cout << endl;
        cout << ans2.size() << endl; 
        for(auto i: ans2) cout << i << " "; 
    }
    
    


}