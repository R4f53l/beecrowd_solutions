#include <bits/stdc++.h>
#define n 65000

using namespace std;

int main()
{
    vector<int> v {2};
    int p = 3;
    while(p<=n){
        bool m = false; 
        int r = sqrt(p);
        for(auto &k: v){
            if(k>r)
                break;
            if(p%k==0){
                m = true; 
                break;
            }
        }
        if(!m)
        v.push_back(p);
        p+=2;
    }
    int q; 
    cin >> q;
    while(q--){
        int x; 
        cin >> x; 
        bool m = false; 
        int r = sqrt(x);
        for(auto &k: v){
            if(k>r)
                break;
            if(x%k==0){
                m = true; 
                break;
            }
        }
        if(!m)
            cout << "Prime" << endl;
        else 
            cout << "Not Prime" << endl;
    }
        
    
    
    
    return 0;
}
