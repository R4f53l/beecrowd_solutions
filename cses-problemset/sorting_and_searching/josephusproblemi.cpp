#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int n; cin >> n; 
    queue<int> q;  

    for(int i = 1; i <= n; i++)
        q.push(i);

    

    while(q.size()){
        q.push(q.front()); q.pop(); //1 2 3 4 -> 2 3 4 1
        cout << q.front() << " ";       
        q.pop();         
    }


}