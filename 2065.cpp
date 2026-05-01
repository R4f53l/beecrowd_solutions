#include <bits/stdc++.h>

using namespace std; 
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main(){_
    int n, m; cin >> n >> m;
    vector<int> v(n); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    for(int i = 0; i < n; i++)
        cin >> v[i]; 
    int soma = -1, maxi = -1;



    for(int i = 0; i < m; i++){
        int a; cin >> a; 
        if(pq.size() == n){
            pair<int, int> k = pq.top(); pq.pop();
            pq.push({a * v[k.second] + k.first, k.second});            
            maxi = max(a * v[k.second] + k.first, maxi);                
            continue;
        }                      
        pq.push({v[i] * a, i});        
        maxi = max(v[i] * a, maxi);         
    }
    cout << maxi << endl;
}