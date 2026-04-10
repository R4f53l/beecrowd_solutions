#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 100

vector<bool> vis (MAX, 0); 

int bfs (int n){
    
    queue<int> q; q.push(n); 
    vis[n] = 1; 

    while(!q.empty()){
        int v = q.front(); q.pop(); 
              

       

    }

}

int main (){
    int n; cin >> n; 
    bfs(n);
}