#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0)

const int MAX = 10; 

int main () {_

    vector<int> fat = {1, 1};

    for (int i = 2; i<MAX; i++)
        fat[i].push_back(i*fat[i-1]);
    
    int n, s = 0;
    cin >> n; 

    for(int i = fat.size()-1; i>=0; i--){
        int a = n/fat[i];
        s += a; 
        n -= a; 
    }
    cout << s << endl;

}